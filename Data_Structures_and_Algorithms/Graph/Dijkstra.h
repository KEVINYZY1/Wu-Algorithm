#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include<vector>
#include<set>
#include<queue>
#include<float.h>//使用DBL_MAX，c++内部定义的double最大值

#include"GraphEdge.h"
#include"../Queue/IndexPriorityQueue.h"
using namespace std;

//Dijkstra算法
//求有权图中一点到其他所有点的最短路径，其实就是生成一个最短路径树 （当然找点对点的最短路径时，可以执行一半就中断）
//要求有权图中不存在负权，至于是有向图还是无向图，并不是特别在意（这里实现针对有向图）
//时间复杂度  O(ElogV)  空间复杂度  O(V)



class Dijkstra{
    public:
        //输入顶点数和边集合来构造有向图，顶点值为0到numVerteVx-1之间
        Dijkstra(int numVerteVx, vector<directedEdge>& prerequisites)
                 :graph_(numVerteVx), edgeTo_(numVerteVx), 
                  distTo_(numVerteVx, DBL_MAX), pqIndexMin_(numVerteVx) {
            for (int i = 0; i < prerequisites.size(); i++) {
                graph_[prerequisites[i].v].push_back(directedEdge(prerequisites[i].v,
                                                               prerequisites[i].w, prerequisites[i].weight));
            }
            s_ = 0;
        }

         //再补充一个接口，方便Johnson算法调用
        Dijkstra(vector<vector<directedEdge> > graph)
            : graph_(graph), edgeTo_(graph.size()), distTo_(graph.size(), DBL_MAX) {
            s_ = 0;
        }

        //s代表了最短路径的起点
        void shortestPath(int s) {
            s_ = s;
            distTo_[s] = 0;
            pqIndexMin_.insert(s,0.0);
            while (!pqIndexMin_.isEmpty()) {
                relax(pqIndexMin_.delMin());
            }
        }

        //返回从起点s到结尾w的最短路径长度
        double distTo(int w) {
            return distTo_[w];
        }

        //返回从起点s到结尾w的最短路径的边集合（边集合的次序是按照从起点s到结尾w的次序）
        vector<directedEdge> pathTo(int w) {
            //利用edgeTo数组倒序查找路径
            vector<directedEdge> t;
            if (distTo(w) == DBL_MAX)
                return t;
            for (auto e = edgeTo_[w]; e.v == s_; e = edgeTo_[e.v])
                t.push_back(e);
            return t;
        }

    private:
        vector<vector<directedEdge> > graph_;
        int s_;

        //用来表示最短路径
        vector<directedEdge> edgeTo_;//edgeTo[i]表示了从起点s到顶点i的最短路径上的最后一条边
        vector<double> distTo_;//distTo[i]表示从起点s到顶点i已知最短路径权重和，注意只是已知，会被不断的更新维护

        //借助于索引优先队列
        //类似于Prim算法，Dijkstra算法也是不断向最短路径树中添加边来构造最短路径树的
        //只不过Prim是将离树最近的非树顶点添加进树中，Dijkstra是将离起点最近的非树顶点添加进入树中。
        indexPriorityQueue<double> pqIndexMin_;//key是顶点值，item是起点s到顶点值key的最短路径长度。


        //松弛操作，Dijkstra算法的核心
        //也正是因为它，才要求权值必须非负
        void relax(int v) {
            for (auto e : graph_[v]) {
                int v = e.v;
                int w = e.w;
                if (distTo_[v] + e.weight < distTo_[w]) {
                    distTo_[w] = distTo_[v] + e.weight;
                    edgeTo_[w] = e;
                    if (pqIndexMin_.exist(w))
                        pqIndexMin_.charge(w, distTo_[w]);
                    else 
                        pqIndexMin_.insert(w, distTo_[w]);
                }
            }
        }
};
#endif