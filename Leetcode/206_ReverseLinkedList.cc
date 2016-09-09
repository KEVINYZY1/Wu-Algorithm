#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//方法1，迭代
class Solution1 {
public:
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

//方法2，递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        return reverseListHelp(head,prev);
    }
private:
    ListNode* reverseListHelp(ListNode* head,ListNode* prev){
        if(!head)
            return prev;
        ListNode* temp=prev;
        prev=head;
        head=head->next;
        prev->next=temp;
        return reverseListHelp(head,prev);
    }
};