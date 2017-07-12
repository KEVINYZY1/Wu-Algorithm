#ifndef PRIM_H
#define PRIM_H

#include<vector>
#include<set>
#include<queue>
#include<priority_queue>

#include"GraphEdge.h"
#include"../Queue/IndexPriorityQueue.h"
using namespace std;

//最小生成树 (图的生成树是一颗含有所有顶点的无环连通子图，最小生成树即该树的所有边的权值和最小)
//针对无向有权图，假定图必然连通，权重可以取任意值，另外假定权重都不相同，保证最小生成树唯一。
//输入的图，顶点是0到numVerteVx-1，然后pair类型的数组中，每个pair元素代表一条路径
//使用邻接表来实现无向有权图

//使用Prim算法     /* 即时算法性能更好，并且与边数关系更小，更适合浓稠图！！！ */
//最小生成树一开始只有一个顶点，然后每次都是将下一条连接树中的顶点与不在树中的顶点且权重最小的边加入树中。
//算法关键，如何快速有效的找到最小权重的横切边。 
//用优先队列维护横切边。



class prim{
    public:
        prim(int numVerteVx, vector<edge> >& prerequisites)
             : graph_(numVerteVx), pqIndexMin_(numVerteVx) {
            for (int i = 0; i < prerequisites.size(); i++) {
                //左右对插，因为这是无向图
                graph_[prerequisites[i].v].insert(make_pair(prerequisites[i].w,prerequisites[i].weight));
                graph_[prerequisites[i].w].insert(make_pair(prerequisites[i].v,prerequisites[i].weight));
            }
        }

        //prim算法的延时实现               时间复杂度O(ElogE) 空间复杂度(E)
        //将最小生成树相邻的所有边放入优先队列中，然后每次从队列中取出最小权重的边，加入最小生成树
        //以边集合的形式返回最小生成树
        vector<edge> lazyPrimMst() {
            vector<bool> visit(graph_.size(), false);
            vector<edge> t;//距离树最近的边，也就是每次要加入树的边
            dfsLazy(visit, 0);//先从顶点0开始dfs一下，同时令优先队列不空
            while (!pqMin_.empty()) {
                edge e = pqMin_.top();
                pqMin_.pop();
                int v = e.v;
                int w = e.w;
                if (visit[v] && visit[w])
                    continue;
                t.push_back(e);
                if(!visit[v])
                    dfsLazy(visit, v);
                if(!visit[w])
                    dfsLazy(visit, w);    
            }
            return t;
        }

        //prim算法的即时实现，优化版         时间复杂度O(ElogV) 空间复杂度(V)
        //使用索引优先队列！！！索引优先队列长度最长为V
        //尝试把优先队列里失效的边删去！！！这是和延时实现最大性能优化的地方
        //每次用索引优先队列维护可能是与最小生成树相邻的最小权重边，每次用最小权重边加入最小生成树
        //以边集合的形式返回最小生成树
        vector<edge> nowPrimMst() {
            vector<bool> visit(graph_.size(),false);
            vector<edge> t(graph_.size());//距离树最近的边，也就是每次要加入树的边
            vector<double> distTo(graph_.size(),INT_MAX);//distTo[w]=t[w].weight 

            distTo[0]=0.0;
            pqIndexMin_.insert(0,0.0);
            while (!pqIndexMin_.empty()) {
                dfsNow(visit, pqIndexMin_.delMin(), t, distTo); 
            }
            return t;
        }

    private:
        vector<set<pair<int, double> > > graph_;//pair的第一个int是另一个端点，第二个double是权值
        //比较边的最小优先队列，延时prim使用
        priority_queue<edge, vector<edge>, [](edge &l, edge &r){
            return (l->weight - r->weight) < 0
        } > pqMin_;
        //索引优先队列，即时prim使用，索引为顶点，值为权值。
        indexPriorityQueue<double> pqIndexMin_;

        void dfsLazy(vector<bool>& visit, int i) {
            visit[i] = true;
            for(auto it = graph_[i].begin(); it != graph_[i].end(); it++) {
                if (visit[it->first] == false)
                    pqMin_.push(edge(i, it->first, it->second));
            }
        }
        void dfsNow(vector<bool>& visit, int i, vector<edge>& t, vector<double>& distTo) {
            visit[i] = true;
            for (auto it = graph_[i].begin(); it != graph_[i].end(); it++) {
                int w = it->first;
                if (visit[w])
                    continue;
                if (distTo[w] > it->second) {
                    t[w] = edge(i,w,it->second);
                    distTo[w] = it->second;
                    if (pqIndexMin_.contains(w))
                        pqIndexMin_.charge(w,it->second);
                    else 
                        pqIndexMin_.insert(w,it->second);
                }
            }
        }

};

#endif