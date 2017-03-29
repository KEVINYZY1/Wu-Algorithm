#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <vector>
#include <cstddef>
#include <random>
using namespace std;

struct SkipListNode{
    SkipListNode(int n, int k=0, int val=0):l(n){
        key=k;
        value=val;
        prev=NULL;
    }
    int key;
    double value;
    SkipListNode *prev;
    struct SkipListLevel{
        SkipListNode *next;
        int span;
    };
    vector<SkipListLevel> l;
};

class SkipList{
public:
    SkipList(){
        //初始化一个表头结点，其层数为32层，每一层均指向NULL
        head_=new SkipListNode(32);
        for(int i=0; i<32; i++){
            head_->l[i].next=NULL;
            head_->l[i].span=0;
        }
        head_->prev=NULL;
        
        tail_=NULL;
        maxLevel_=1;
        length_=0;
    }

    bool insertNode(int k, int val){
        vector<SkipListNode*> update(32, NULL);//记录被插入的结点，在每一层的前一个结点
        vector<int> rank(32,0);//rank[]记录每一层位于插入节点的前一个节点的排名

        SkipListNode *start=head_;
        for(int i=0; i<=maxLevel_; i++){
            // 存储rank值是为了交叉快速地到达插入位置
            rank[i] = i == (maxLevel_-1) ? 0 : rank[i+1];

            while(start->l[i].next!=NULL){
                if(val > start->l[i].next->value){
                    start=start->l[i].next;
                    rank[i] += start->l[i].span;
                }
                else if (val < start->l[i].next->value){
                    update[i]=start;
                    continue;
                }
                else{
                    //分值一致，不考虑key了
                    return false;//已经存在结点
                }
            }
        }

        int level=getRandomNum();
        if(level>maxLevel_){
            for(int i=maxLevel_; i<level; i++){
                rank[i]=0;
                update[i]=head_;
                update[i]->l[i].span=length_;
            }
            maxLevel_=level;
        }

        auto newNode=new SkipListNode(level,k,val);
        for (int i = 0; i < level; i++) {
            //类似于链表插入
            newNode->l[i].next = update[i]->l[i].next;
            update[i]->l[i].next = newNode;
            // 更新插入节点的span值
            newNode->l[i].span = update[i]->l[i].span - (rank[0] - rank[i]);
            // 更新插入点的前一个节点的span值
            update[i]->l[i].span = (rank[0] - rank[i]) + 1;
        }
        // 更新高层的span值
        int i;
        for (i = level; i < maxLevel_; i++) {
            update[i]->l[i].span++;
        }
        // 设定插入节点的backward指针
        newNode->prev = (update[0] == head_) ? NULL : update[0];
        if (newNode->l[i].next)
            newNode->l[i].next->prev = newNode;
        else
            tail_ = newNode;

        length_++;
        return true;
    }

    bool deleteNode(int k, int val){

        length_--;
        return true;
    }
private:
    int length_;
    SkipListNode *head_, *tail_;
    int maxLevel_;
    int getRandomNum(){//获取1到32之间随机数
        uniform_int_distribution<int> dist(1, 32);
        random_device rd;
        return dist(rd);
    }
};

#endif