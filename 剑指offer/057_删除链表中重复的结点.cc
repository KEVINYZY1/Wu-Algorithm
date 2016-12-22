#include<cstdlib>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
    }
};

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
		if(pHead==NULL||pHead->next==NULL)
            return pHead;
        ListNode *dump=new ListNode(-1);
        dump->next=pHead;
        auto temp=dump;
        while(temp &&temp->next){
            if(temp->next->next==NULL)
                break;
            if(temp->next->val==temp->next->next->val){
                auto node=temp->next->next->next;
                while(node!=NULL && node->val==temp->next->val){
                    node=node->next;
                }
                temp->next=node;
            }
            else{
                temp=temp->next;
            }
        }
        pHead=dump->next;
        delete dump;
        return pHead;
    }
};