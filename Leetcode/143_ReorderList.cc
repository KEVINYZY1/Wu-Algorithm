#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//数组也有类似的题目
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;
        auto slow=head;
        auto fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        auto newHead=reverseList(slow->next);
        slow->next=NULL;
        slow=head;
        while(slow && newHead){
            auto node=slow->next;
            slow->next=newHead;
            newHead=newHead->next;
            slow->next->next=node;
            slow=node;
        }
    }
private:
     ListNode* reverseList(ListNode* head) {
        ListNode*prev=NULL;
        while(head){
            ListNode* temp=prev;
            prev=head;
            head=head->next;
            prev->next=temp;
        }
        return prev;
     }
};