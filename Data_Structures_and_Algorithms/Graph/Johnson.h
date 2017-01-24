#ifndef JOHNSON_H
#define JOHNSON_H

#include<vector>
#include<set>
#include<queue>
#include<float.h>//使用DBL_MAX，c++内部定义的double最大值
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
1 构造原图的扩展图G’=(V’, E’)，V’=V∪{s}，E’=E∪{(s, u):u∈ V}；
2 在G’中以s为起始顶点应用Bellman-Ford算法，求解各顶点到顶点s的最短路径；
3 对原图重赋权；
4 重赋权后以图中每个顶点为起始顶点，应用Dijkstra算法求解每对顶点之间的最短路径；
5 由于重赋权改变了图中路径的长度，最后需要还原上一步骤中求得最短路径的长度；
*/


//有向图的边定义，默认v指向w
struct directedEdge{
    int v;
    int w;
    double weight;
    directedEdge(){
        v=-1;
    }
    directedEdge(int v, int w, double weight){
        this->v=v;
        this->w=w;
        this->weight=weight;
    }
};

#endif