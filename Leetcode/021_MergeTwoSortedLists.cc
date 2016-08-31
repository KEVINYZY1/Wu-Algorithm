#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dump=new ListNode(-1);
        ListNode* newHead;
        newHead=dump;//这里重新做时候，犯了错误，要仔细理解指针的含义
        while(l1&&l2){
            if(l1->val<l2->val){
                newHead->next=l1;
                l1=l1->next;
            }
            else{
                newHead->next=l2;
                l2=l2->next;
            }
            newHead=newHead->next;
        }
        if(l1)newHead->next=l1;
        else if(l2)newHead->next=l2;
        newHead=dump->next;
        delete dump;
        return newHead;
    }
};