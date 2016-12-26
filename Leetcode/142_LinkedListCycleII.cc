#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto pHead=head;
        if(pHead==NULL)
            return NULL;
        auto slow=pHead;
        auto fast=pHead->next;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;//题目保证了有环才可以这么写
            if(fast==slow)
                break;
        }
        if(fast!=slow)
            return NULL;
        slow=slow->next;
        int len=1;
        while(slow!=fast){
            len++;
            slow=slow->next;
        }
        slow=pHead;
        fast=pHead;
        while(len){
            len--;
            fast=fast->next;
        }
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};