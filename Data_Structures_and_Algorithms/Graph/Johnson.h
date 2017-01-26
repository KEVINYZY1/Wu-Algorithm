#ifndef JOHNSON_H
#define JOHNSON_H

#include<vector>
#include<set>
#include<queue>
#include<float.h>//使用DBL_MAX，c++内部定义的double最大值
#include<assert>

#include"GraphEdge.h"
#include"BellmanFord.h"
#include"Dijkstra.h"

using namespace std;

//Johnson算法
//多源最短路径算法
//Johnson算法可以在O(VElgV)时间内求解每对顶点之间的最短路径。对于稀疏图，该算法在要好于Floyd算法。
//如果以每个顶点作为起始顶点，用Dijkstra算法求解单源最短路径，则可以求解全源最短路径，算法复杂度为VElgV。但是对含有负权值的图，Dijkstra算法将失效。

//Johnson算法运用了“重赋权”技术，即将原图中每条边的权值ω重新赋值为ω’，并且具有以下两个性质：
//1 对所有顶点对u,v，路径p是以权值为ω的原图的最短路径，当且仅当路径p也是以权值为ω’的图的最短路径；
//2 对于所有的边(u, v)，ω’(u, v)是非负数。

//对带权有向图G=(V, E)，边(u, v)的权值ω(u, v)，设h为顶点映射到实数域的映射函数。对图中每条边(u, v)，定义：
//ω'(u, v) = ω(u, v) + h(u) – h(v)
//满足性质1
//满足性质2，即保证重赋权后权值非负
//在不存在负环的前提下，定义h(u)=lenmin(s, u)，即顶点s到顶点u的最短路径，那么对所有的边(v, u)∈V’，h(u)≦ h(v) + ω(v, u)。
//那么在h(u)=lenmin(s, u)的条件下，便可满足ω'(u, v) = ω(u, v) + h(u) – h(v) ≧ 0
/*步骤
1 构造原图的扩展图G’=(V’, E’)，V’=V∪{s}，E’=E∪{(s, u):u∈ V}；注意，扩展图的新顶点到原来的顶点权重都是0
2 在G’中以s为起始顶点应用Bellman-Ford算法，求解各顶点到顶点s的最短路径；
3 对原图重赋权；
4 重赋权后以图中每个顶点为起始顶点，应用Dijkstra算法求解每对顶点之间的最短路径；
5 由于重赋权改变了图中路径的长度，最后需要还原上一步骤中求得最短路径的长度；
*/



class Johnson{
    public:
        //输入顶点数和边集合来构造有向图，顶点值为0到numVerteVx-1之间
        Johnson(int numVerteVx, vector<directedEdge>& prerequisites)
        :graph_(numVerteVx){
            for(int i=0; i<prerequisites.size(); i++){
                graph_[prerequisites[i].v].insert(directedEdge(prerequisites[i].v,
                                                               prerequisites[i].w, prerequisites[i].weight));
            }
            //在原图的基础上添加一个顶点s，新顶点s到其他点的权重为0
            int s=numVerteVx;
            graph_.push_back(set<directedEdge>());
            for(int i=0; i<numVerteVx; i++){
                graph_[numVerteVx].insert(directedEdge(s,i,0));
            }

            //使用BellmanFord算法，以s为单源起点，算出其他的最短路径
            //如果有负环的情况，BellmanFord算法会自动报错
            BellmanFord newG(graph_);
            newG.shortestPath(s);
            assert(!newG.hasNegativeCycle());
            
            //对原图重新赋值权重
            //这里需要注意的是，我们存放图使用了set容器，无法再对容器的key做出改变，重新申请个图
            vector<set<directedEdge> > newGraph(numVerteVx);
            for(int i=0; i<numVerteVx; i++){
                for (auto it=graph_[i].begin(); it!=graph_[i].end(); it++){
                    //ω'(u, v) = ω(u, v) + h(u) – h(v)
                    newGraph[i].insert(directedEdge(it->v, it->w,
                                        it->weight+newG.distTo(it->v)-newG.distTo(it->w)));
                }
            }

            //使用Dijkstra算法
            for(int s=0; s<numVerteVx; s++){
                distTo_[s][s]=0;
                Dijkstra temp(newGraph);
                temp.shortestPath(s);
                for(int i=0; i<numVerteVx; i++){
                    if(i==s)
                        continue;
                    //注意，这里算出的最短路径必须要减去之前给权重加上的部分。
                    distTo_[s][i]=temp.distTo(i)-(newG.distTo(it->v)-newG.distTo(it->w)));
                }
            }

        }

        //返回从s到w的最短路径
        double findShortestPathCost(int s, int w){
            assert(!hasNegativeCycle());
            assert(s>=0 && s<graph_.size());
            assert(w>=0 && w<graph_.size());
            return distTo_[s][w];
        }

    private:
        vector<set<directedEdge> > graph_;
        vector<vector<double> > distTo_;
        //vector<vector<directedEdge> > edgeTo_;这个其实也好求，懒得弄了

};
#endif