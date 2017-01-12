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
            int temp=p;
            while(uf_[p]!=p)
                p=uf_[p];
            //在这里路径压缩！！
            while(temp != uf_[p]){
                int tempId = uf_[temp];
                uf_[temp] = uf_[p];
                temp = tempId;
            }
            return p;
        }
        void union (int p, int q){
            assert(p<UF_SIZE);
            int pRoot=find(p);
            int qRoot=find(q);
            if(pRoot==qRoot)
                return;

            int allWeight=weight_[pRoot]+weight_[qRoot];
            //每次比较union大小，只比较根在weight_数组中的值
            if(weight_[pRoot]<weight_[qRoot]){
                uf_[pRoot]=qRoot;
                weight_[qRoot]=allWeight;
            }
            else{
                uf_[qRoot]=pRoot;
                weight_[pRoot]=allWeight;
            }
            count_--;
        }

    private:
        vector<int> uf_;
        vector<int> weight_;
        int count_;
};

#endif