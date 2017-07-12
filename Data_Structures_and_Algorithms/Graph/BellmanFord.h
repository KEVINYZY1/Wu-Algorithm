#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include<vector>
#include<set>
#include<queue>
#include<float.h>//使用DBL_MAX，c++内部定义的double最大值

#include"GraphEdge.h"
using namespace std;

//BellmanFord算法
//加权有向图中找出起点s到其他点的最短路径
//权重可以是负数，图可以有环，但是不能有负环，如果存在负环，将会被检测出来
//每轮算法relaxE条边，一共进行V轮，relax边的次序没有要求！！
//实际上是动态规划
//时间复杂度  O(EV)  空间复杂度  O(V)



class weightedDirectedGraphCycle;
class BellmanFord{
    public:
        //输入顶点数和边集合来构造有向图，顶点值为0到numVerteVx-1之间
        BellmanFord(int numVerteVx, vector<directedEdge>& prerequisites)
                    : graph_(numVerteVx), edgeTo_(numVerteVx), distTo_(numVerteVx, DBL_MAX) {
            for (int i = 0; i < prerequisites.size(); i++) {
                graph_[prerequisites[i].v].push_back(directedEdge(prerequisites[i].v,
                                                               prerequisites[i].w, prerequisites[i].weight));
            }
            s_ = 0;
            cost_ = 0;
        }

        //再补充一个接口，方便Johnson算法调用
        BellmanFord(vector<vector<directedEdge> > graph)
                    : graph_(graph), edgeTo_(graph.size()), distTo_(graph.size(), DBL_MAX) {
            s_ = 0;
            cost_ = 0;
        }

        //s代表了最短路径的起点
        void shortestPath(int s) {
            s_ = s;
            distTo_[s] = 0;
            vector<bool> onQueue(graph_.size(), false);//防止
            onQueue[s_] = true;
            q.push(s_);
            
            while (!q.empty() && !hasNegativeCycle()) {//一旦发现负环，就停止执行
                int v = q.front();
                q.pop();
                relax(v, onQueue);
            }
        }

        bool hasNegativeCycle() {
            return !cycle_.empty();
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

        //辅助队列
        queue<int> q;

        int cost_;//relax操作被调用的次数

        //松弛操作
        //利用onQueue保证队列中不出现重复的顶点，更重要的是
        //在前一轮中被改变了edgeto和distto值的顶点，会在下一轮中被处理。
        void relax(int v, vector<bool>& onQueue) {
            for(auto e : graph_[v]) {
                int v = e.v;
                int w = e.w;
                if (distTo_[v] + e.weight < distTo_[w]) {
                    distTo_[w] = distTo_[v]+e.weight;
                    edgeTo_[w] = e;
                    if (onQueue[w] == false) {
                        q.push(w);
                        onQueue[w] = true;
                    }
                }
                if (cost_++ % graph_.size() == 0) {
                    findNegativeCycle();
                    if (hasNegativeCycle()) 
                        return;  // found a negative cycle
                }
            }
        }

        vector<directedEdge> cycle_;
        void findNegativeCycle() {
            int V = edgeTo_.size();
            vector<directedEdge> spt;
            for (int v = 0; v < V; v++)
                if (edgeTo_[v].v != -1)
                    spt.push_back(edgeTo_[v]);
            //每relax一轮，都把从edgeTo数组中的边判断是否有环
            weightedDirectedGraphCycle wc(V, spt);
            if (wc.isNegativeCycle())
                cycle_.swap(spt);
        }
};

//辅助类，判断一个有权有向图是否存在负环，Dfs
class weightedDirectedGraphCycle{
    public:
        //输入顶点数和边集合来构造有向图，顶点值为0到numCourses-1之间
        weightedDirectedGraphCycle(int numCourses, vector<directedEdge>& prerequisites)
                        : graph_(numCourses), hasNegativeCycle_(false), visit_(numCourses, false), 
                          onStack_(numCourses, false), edgeTo_(numCourses) {
            for (int i = 0; i<prerequisites.size(); i++) {
                graph_[prerequisites[i].v].push_back(directedEdge(prerequisites[i].v,
                                                               prerequisites[i].w, prerequisites[i].weight));
            }
            for (int v = 0; v < numCourses; v++)
                if (!visit_[v]) 
                    dfs(v);
        }

        bool isNegativeCycle() {
            return hasNegativeCycle_;
        }

    private:
        vector<vector<directedEdge> > graph_;
        vector<bool> visit_;
        vector<bool> onStack_;
        vector<directedEdge> edgeTo_;

        bool hasNegativeCycle_;
        void dfs(int v) {
            onStack_[v] = true;
            visit_[v] = true;
            for (auto e : graph_[v]) {
                int w = e.w;
                if (hasNegativeCycle_)
                    return;
                if (visit_[w] == false) {
                    edgeTo_[w]=e;
                    dfs(w);
                } else if (onStack_[w] == false) {
                    int cost = 0;
                    auto f = e;
                    while (f.v != w) {
                        cost += f.weight;
                        f = edgeTo_[f.v];
                    }
                    if (cost < 0)
                        hasNegativeCycle_ = true;
                }
            }
        }
};
#endif