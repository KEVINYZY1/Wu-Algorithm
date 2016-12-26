#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* dump;
        dump=new ListNode (-1);
        dump->next=head;
        ListNode* cur=head;
        
        while(cur && cur->next){
            
            auto pre=dump;
            while(pre->next!=NULL && pre->next->val<cur->next->val){
                pre=pre->next;
            }
            if(pre==cur){
                cur=cur->next;
                continue;
            }
            
            ListNode *node=cur->next->next;    
            cur->next->next=pre->next;
            pre->next=cur->next;
            cur->next=node;
            //cur=cur->next;
        }
        
        //最后要删除new出来的节点
        ListNode* newHead=dump->next;
        delete dump;
        return newHead;
    }
};