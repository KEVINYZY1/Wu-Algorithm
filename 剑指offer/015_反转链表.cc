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

//输入一个链表，反转链表后，输出链表的所有元素。

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead==NULL)
            return NULL;
        ListNode* pre=NULL;
        auto cur=pHead;
        while(cur!=NULL){
            auto temp=pre;
            pre=cur;
            cur=cur->next;
            pre->next=temp;
        }
        return pre;
    }
};