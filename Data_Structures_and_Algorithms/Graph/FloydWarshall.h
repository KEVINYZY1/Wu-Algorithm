#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H


#include<vector>
#include<set>
#include<queue>
#include<float.h>//使用DBL_MAX，c++内部定义的double最大值
#include<cassert>

#include"GraphEdge.h"
using namespace std;

//FloydWarshall算法
//多源最短路径算法
//Floyd算法是一个经典的动态规划算法，用来寻找点对点的最短路径
/*
*从任意节点A到任意节点B的最短路径不外乎两种可能
*1 是直接从A到B，2 是从A经过若干个节点X到B。
*所以，我们假设Dis(AB)为节点A到节点B的最短路径的距离，对于每一个节点X，我们检查Dis(AX) + Dis(XB) < Dis(AB)是否成立
*如果成立，证明从A到X再到B的路径比A直接到B的路径短，我们便设置Dis(AB) = Dis(AX) + Dis(XB)
*这样一来，当我们遍历完所有节点X，Dis(AB)中记录的便是A到B的最短路径的距离。
*/
//不需要担心有环和负权重的问题，当然存在负环还是没有最短路径
//时间复杂度  O(V3)  空间复杂度  O(V2)


class FloydWarshall{
    public:
        //输入顶点数和边集合来构造有向图，顶点值为0到numVerteVx-1之间
        FloydWarshall(int numVerteVx, vector<directedEdge>& prerequisites)
        :graph_(numVerteVx), edgeTo_(numVerteVx, vector<directedEdge>()), 
        distTo_(numVerteVx, vector<double>(numVerteVx,DBL_MAX)), hasNegativeCycle_(false){
            for (int i = 0; i < prerequisites.size(); i++) {
                graph_[prerequisites[i].v].insert(directedEdge(prerequisites[i].v,
                                                               prerequisites[i].w, prerequisites[i].weight));
            }
            //DP辅助数组初始化
            for (int v = 0; v < numVerteVx; v++) {
                for (directedEdge e : graph_[v]) {
                    distTo_[e.v][e.w] = e.weight;
                    edgeTo_[e.v][e.w] = e;
                }
                //防止有顶点到自己本身也需要距离，那就sb了
                if (distTo_[v][v] >= 0.0) {
                    distTo_[v][v] = 0.0;
                    //edgeTo_[v][v] = null;
                }
            }
            // 算法核心
            for (int i = 0; i < numVerteVx; i++) {
            // compute shortest paths using only 0, 1, ..., i as intermediate vertices
                for (int v = 0; v < numVerteVx; v++) {
                    if (edgeTo_[v][i].v==-1) //小技巧，如果不存在边，则边的默认初始化函数会把v初始化为-1
                        continue;  
                    for (int w = 0; w < numVerteVx; w++) {
                        if (distTo_[v][w] > distTo_[v][i] + distTo_[i][w]) {
                            distTo_[v][w] = distTo_[v][i] + distTo_[i][w];
                            edgeTo_[v][w] = edgeTo_[i][w];
                        }
                    }
                    //如果顶点到自身小于0，那肯定是出现了负环！！
                    if (distTo_[v][v] < 0.0) {
                        hasNegativeCycle_ = true;
                        return;
                    }
                }
            }
        }

        //返回从s到w的最短路径
        double findShortestPathCost(int s, int w) {
            assert(!hasNegativeCycle());
            assert(s >= 0 && s < graph_.size());
            assert(w >= 0 && w < graph_.size());
            return distTo_[s][w];
        }
        vector<directedEdge> findShortestPath(int s, int w) {
            assert(!hasNegativeCycle());
            assert(s >= 0 && s < graph_.size());
            assert(w >= 0 && w < graph_.size());
            vector<directedEdge> t;
            auto e = edgeTo_[s][w];
            while (e.v != s) {
                assert(e.v != -1);
                t.push_back(e);
                w = e.v;
                e = edgeTo_[s][w];    
            }
            reverse(t.begin(), t.end());
            return t;
        }

        bool hasNegativeCycle() {
            return hasNegativeCycle_;
        }

    private:
        vector<set<directedEdge> > graph_;
        vector<vector<double> > distTo_;
        vector<vector<directedEdge> > edgeTo_;
        bool hasNegativeCycle_;
};
#endif