#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dump=new ListNode(-1);
        dump->next=head;
        auto storeDump=dump;
        while(dump->next){
            if(dump->next->val==val){
                auto temp=dump->next->next;
                delete dump->next;
                dump->next=temp;
            }
            else dump=dump->next;
        }
        dump=storeDump;
        head=dump->next;
        delete dump;
        return head;
    }
};