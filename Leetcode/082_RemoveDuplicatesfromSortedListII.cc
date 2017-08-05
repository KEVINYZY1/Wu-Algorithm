#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 //双指针
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *dump = new ListNode(head->val - 1);
        dump->next = head;
        auto prev = dump;
        auto cur = dump->next;
        bool duplicate = false;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                ListNode *temp = cur->next;
                cur->next = temp->next;
                delete temp;
                duplicate = true;
            } else if (duplicate) {//关键，一个也不保留
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
                duplicate = false;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        head = dump->next;
        delete dump;
        return head;
    }
};