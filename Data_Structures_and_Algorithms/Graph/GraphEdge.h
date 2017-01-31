#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H
//这里分别定义有向图和无向图的边，提供给图算法使用


//无向图的边定义
struct edge{
    int v;
    int w;
    double weight;
    edge(int v, int w, double weight){
        this->v=v;
        this->w=w;
        this->weight=weight;
    }
};


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

//网络流的边定义，默认v指向w
struct flowEdge{
    int v;
    int w;
    double maxFlow;
    flowEdge(int v, int w, double maxFlow){
        this->v=v;
        this->w=w;
        this->maxFlow=maxFlow;
    }
};

#endif