#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//不是严格的分区
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dump=new ListNode(-1);
        dump->next=head;
        head=dump;
        ListNode *head2=new ListNode(-1);
        ListNode *storeHead2=head2;
        while(head->next){
            if(head->next->val>=x){
                head2->next=head->next;
                head2=head2->next;
                head->next=head->next->next;
                head2->next=NULL;
            }else{
                head=head->next;
            }
        }
        head->next=storeHead2->next;
        head=dump->next;
        delete dump;
        delete storeHead2;
        return head;
    }
};