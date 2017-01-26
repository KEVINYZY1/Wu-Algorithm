#ifndef TOPOLOGICAL_SHORTEST_PATH_H
#define  TOPOLOGICAL_SHORTEST_PATH_H

#include<vector>
#include<set>
#include<queue>
#include<float.h>//使用DBL_MAX，c++内部定义的double最大值
 
#include"GraphEdge.h"
using namespace std;

//比Dijkstra更快更简单
//要求无环有向加权图，并不在意权重是否为负
//还可以解决最长路径问题，其实就是把所有权重取相反数，求最短路径，即是最长路径
//从无环有向图的拓扑排序中扩展而来
//先dfs找出拓扑排序，然后按照拓扑排序对顶点依次进行relax操作即可
//时间复杂度   O(E+V)   空间复杂度  O(V)


class topologicalShortestPath{
    public:
        //输入顶点数和边集合来构造有向图，顶点值为0到numVerteVx-1之间
        topologicalShortestPath(int numVerteVx, vector<directedEdge>& prerequisites)
        :graph_(numVerteVx), edgeTo_(numVerteVx), distTo_(numVerteVx, DBL_MAX){
            for(int i=0; i<prerequisites.size(); i++){
                graph_[prerequisites[i].v].insert(directedEdge(prerequisites[i].v,
                                                               prerequisites[i].w, prerequisites[i].weight));
            }
            s_=0;
        }

        //找出最短路径
        void findShortestPathFromS(int s){
            s_=s;
            distTo_[s]=0;
            findTopological();
            for(int i=0; i<topological_.size(); i++){
                relax(topological_[i]);
            }
        }

        /*下面两个操作和Dijkstra算法中操作是一样的*/
        //返回从起点s到结尾w的最短路径长度
        double distTo(int w){
            return distTo_[w];
        }

        //返回从起点s到结尾w的最短路径的边集合（边集合的次序是按照从起点s到结尾w的次序）
        vector<directedEdge> pathTo(int w){
            //利用edgeTo数组倒序查找路径
            vector<directedEdge> t;
            if(distTo(w)==DBL_MAX)
                return t;
            for(auto e=edgeTo_[w];e.v==s_;e=edgeTo_[e.v])
                t.push_back(e);
            return t;
        }

    private:
        vector<set<directedEdge> > graph_;
        int s_;

        //用来表示最短路径
        vector<directedEdge> edgeTo_;//edgeTo[i]表示了从起点s到顶点i的最短路径上的最后一条边
        vector<double> distTo_;//distTo[i]表示从起点s到顶点i已知最短路径权重和，注意只是已知，会被不断的更新维护

        //松弛操作
        //是对从v出发的所有边进行松弛操作！！！
        void relax(int v){
            for(auto e : graph_[v]){
                int v=e.v;
                int w=e.w;
                if(distTo_[v]+e.weight<distTo_[w]){
                    distTo_[w]=distTo_[v]+e.weight;
                    edgeTo_[w]=e;
                }
            }
        }
        //找出拓扑排序
        vector<int> topological_;
        void findTopological(){
            vector<int> in(graph_.size(), 0);
            for(int i=0; i<graph_.size(); i++){
                for(auto e : graph_[i]){
                    in[e.w]++;
                }
            }
            queue<int> q;
            for (int i = 0; i<graph_.size(); ++i) {
                if (in[i] == 0) 
                    q.push(i);
            }
            while (!q.empty()) {
                int t = q.front();
                topological_.push_back(t);
                q.pop();
                for (auto a : graph_[t]) {
                    --in[a];
                if (in[a] == 0) 
                    q.push(a);
                }
            }
            //检查是不是可能有环
            for (int i = 0; i<graph_.size(); ++i) {
                if (in[i] != 0) 
                    return;
            }
        }
};

#endif