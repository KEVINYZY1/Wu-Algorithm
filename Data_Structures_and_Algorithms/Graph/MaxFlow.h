#ifndef MAX_FLOW_H
#define MAX_FLOW_H

#include <queue>
#include<vector>
#include<set>
#include"GraphEdge.h"
#include<float.h>//使用DBL_MAX，c++内部定义的double最大值
using namespace std;

//网络流，有两点限制：
    //容量限制：管道的流量不能超过容量。
    //流量守恒：流入管道连接组件的流量等于流出的流量。

//残存网络：网络流的边是(c,v)，c是当前流量，v是最大容量。将边更新为v-c，并添加大小为c的反向边。
/*为什么要加反向边*/   //反向边的作用就是给程序一个可以后悔的机会

//增广路径：增广路劲是残存网络从S到T的一条简单路劲。
//最大流最小切割定理：网络的最大流必然无法超过网络的最小割。对网络的任意割，其净流量的都是相等的
//因此，我们可以得出结论，残留网络一旦找不到增广路径，那么当前流就是最大流。（充分必要）

//Ford-Fulkerson是一种求解最大流的方法，是一种指导思想，过程如下：
/*
1. 流网络中所有顶点对的流大小清零（此时，网络流为零）
2. 每次迭代，通过寻找一条增广路径来增加流的值
3. 无法找到增广路径时，迭代结束
可以看到，最关键问题是如何寻找增广路径，而Ford-Fulkerson方法的效率正取决于此。
*/
//但是，Ford-Fulkerson并没有告诉我们如何寻找增广路径。所以，它是个方法，而不是算法



//下面的实现，是EdmondsKarp算法，寻找增广路径的方法是BFS
//时间复杂度  O(VE2)
class EdmondsKarp{
    public:
        //输入顶点数和边集合来构造有向图，顶点值为0到numVerteVx-1之间
        EdmondsKarp(int numVerteVx, vector<flowEdge>& prerequisite)
        :graph_(numVerteVx), flow_(numVerteVx, vector<double>(numVerteVx,0)), 
        augmentingPath_(numVerteVx,0), maxFlow_(numVerteVx, vector<double>(numVerteVx,0)){
            for(int i=0; i<prerequisites.size(); i++){
                graph_[prerequisites[i].v].insert(flowEdge(prerequisites[i].v,
                                                           prerequisites[i].w, 
                                                           prerequisites[i].maxFlow));
                maxFlow_[prerequisites[i].v, prerequisites[i].w]=prerequisites[i].maxFlow;
            }
            
        }

        int findMaxFlow(int s, int t){
            int maxFlowSum=0;
            queue<int>q;//BFS必备
            while(true){
                vector<double> res(graph_.size(), 0);//残余网络
                res[s]=DBL_MAX;//源点的残留网络要置为无限大
                augmentingPath_[s]=-1;
                q.push(s);
                //BFS, BFS 的时间都是O(E)
                while(!q.empty()){
                    int v=q.front();
                    q.pop();
                    //除了s和t的所有顶点
                    for(int i=0; i<=t; i++){
                        if(!res[i] && flow_[v][i]<maxFlow_[v][i]){
                            q.push(i);
                            augmentingPath_[i]=v;
                            res[i]=min(maxFlow_[v][i]-flow_[v][i], res[v]);//这里类似dp，如果有增广路，那么res[t]就是增广路的最小权
                        }
                    }
                    if(res[t]==0)//没有增广路径
                        break;
                    int k=t;
                    while(augmentingPath_[k]!=-1){
                        flow_[augmentingPath_[k]][k]+=res[t];//正向边加上新的流量  
                        flow_[k][augmentingPath_[k]]-=res[t];//反向边要减去新的流量，反向边的作用是给程序一个后悔的机会  
                        k=augmentingPath_[k];
                    }
                    maxFlowSum+=res[t];
                }
            }
            return maxFlowSum;
        }
    private:
        vector<set<flowEdge> > graph_;
        vector<vector<double> > flow_;//记录实际两条边之间的流大小
        vector<vector<double> > maxFlow_;//边容量 
        vector<double> augmentingPath_;
};

#endif