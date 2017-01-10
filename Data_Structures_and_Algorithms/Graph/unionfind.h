#ifndef UNIONFIND_H
#define UNIONFIND_H

#include<vector>
#include<cassert>
using namespace std;

#define UF_SIZE 128
//并查集
//加权并且路径压缩的quick-union算法

class weightedQuickUnionUF{
    public:
        weightedQuickUnionUF (int size=UF_SIZE){
            //初始化，先确定并查集的大小，并且让并查集有大小个数的连通量，每个连通量的大小都是1
            count_=UF_SIZE;
            for(int i=0;i<UF_SIZE;i++){
                uf_.push_back(i);
                weight_.push_back(1);
            }
        }
        int count (){
            return count_;
        }
        bool isConnected (int p, int q){
            return find(p)==find(q);
        }
        int find (int p){
            assert(p<UF_SIZE);
            while(uf_[p]!=p)
                p=uf_[p];
            return p;
        }
        void union (int p, int q){
            assert(p<UF_SIZE);
            int pRoot=find(p);
            int qRoot=find(q);
            if(pRoot==qRoot)
                return;
            int allWeight=weight[p]+weight[q];
            //
            if(weight[p]<weight[q]){
                while(uf_[p]!=p){
                    weight[p]=allWeight;
                    uf_[p]=qRoot;
                    p=uf_[p];
                }
                while(uf_[q]!=q){
                    weight[q]=allWeight;
                    uf_[q]=pRoot;
                    q=uf_[q];
                }
            }
            else{
                while(uf_[q]!=q){
                    weight[q]=allWeight;//这里的权值也可以只更新根的对应权值
                    uf_[q]=pRoot;//顺手压缩了路径，当然也可以不用压缩，直接默认改写权值小的连通量的根的uf_值
                    q=uf_[q];
                }
                while(uf_[p]!=p){
                    weight[p]=allWeight;
                    uf_[p]=qRoot;
                    p=uf_[p];
                }
            }
            count--;
        }

    private:
        vector<int> uf_;
        vector<int> weight_;
        int count_;
};

#endif