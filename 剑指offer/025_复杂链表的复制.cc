#include<cstdlib>

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

//输入一个复杂链表
//（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
//（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(pHead==NULL)
            return NULL;
        //每个结点后面加一个
        auto storepHead=pHead;
        while(pHead!=NULL){
            auto temp=pHead->next;
            pHead->next=new RandomListNode(pHead->label);
            pHead->next->next=temp;
            pHead=pHead->next->next;
        }
        pHead=storepHead;
        while(pHead!=NULL){
            if(pHead->random!=NULL)//随机指针有可能为空，真是害人
            	pHead->next->random=pHead->random->next;
            pHead=pHead->next->next;
        }
        //再把链表拆开
        pHead=storepHead;
        auto newHead=pHead->next;
        while(pHead!=NULL){
            auto temp=pHead->next;
            pHead->next=pHead->next->next;
            pHead=pHead->next;
            if(pHead!=NULL)
                temp->next=pHead->next;
        }
        return newHead;
    }
};