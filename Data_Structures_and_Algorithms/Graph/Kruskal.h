#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <set>
#include <queue>
#include <queue>

#include "GraphEdge.h"
#include "UnionFind.h"
using namespace std;

//最小生成树 (图的生成树是一颗含有所有顶点的无环连通子图，最小生成树即该树的所有边的权值和最小)
//针对无向有权图，假定图必然连通，权重可以取任意值，另外假定权重都不相同，保证最小生成树唯一。
//输入的图，顶点是0到numVerteVx-1，然后pair类型的数组中，每个pair元素代表一条路径
//使用邻接表来实现无向有权图

//kruskal算法   时间复杂度O(ElogE) 空间复杂度(E) 更适合稀疏图！！
//按照边的权重由小到大来处理它们，加入的边不会与已有的边构成环，直到树有v-1个边为止。由森林合成树。
//利用优先队列和并查集来完成该算法！！



class kruskal{
    public:
        kruskal(int numVerteVx, vector<edge>& prerequisites)
                : graph_(numVerteVx) {
            for (int i = 0; i<prerequisites.size(); i++) {
                //左右对插，因为这是无向图
                graph_[prerequisites[i].v].insert(make_pair(prerequisites[i].w,prerequisites[i].weight));
                graph_[prerequisites[i].w].insert(make_pair(prerequisites[i].v,prerequisites[i].weight));
            }
        }

        vector<edge> kruskalMst() {
            weightedQuickUnionUF u(graph_.size());
            vector<edge> t;
            //将图的所有边插入优先队列中
            for (int i = 0; i < graph_.size(); i++) {
                for (auto it = graph_[i].begin(); it != graph_[i].end(); it++) {
                    pqMin_.push(edge(i, it->first, it->second));
                }
            }
            while (!pqMin_.empty() && t.size() < graph_.size()) {
                edge e = pqMin_.top();
                pqMin_.pop();
                if(u.isConnected(e.v, e.w))
                    continue;
                u.unionTwo(e.v, e.w);
                t.push_back(e);
            }
            return t;
        }

    private:
        vector<set<pair<int, double>>> graph_;//pair的第一个int是另一个端点，第二个double是权值
        //比较边的最小优先队列
        priority_queue<edge, vector<edge>, [](edge &l, edge &r) {
            return (l->weight-r->weight) < 0;
        }> pqMin_;
};
#endif