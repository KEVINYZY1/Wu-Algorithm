#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        auto storeHead = head;
        while (head && head->next) {
            if (head->val == head->next->val) {//小心多个重复的情况
                auto temp = head->next->next; 
                delete head->next;
                head->next = temp;
            }
            else head = head->next;
        }
        return storeHead;
    }
};