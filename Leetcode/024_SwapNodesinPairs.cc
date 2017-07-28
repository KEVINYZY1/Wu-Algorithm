#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//两处限制：1.空间复杂度O(1) 2.不能靠修改链表节点中的值来达到题目要求
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* dump = new ListNode(-1);
        dump->next = head;
        ListNode* prev = dump;
        while (cur && cur->next) {
            ListNode* temp = cur->next->next;
            cur->next->next = prev->next;
            prev->next = cur->next;
            cur->next = temp;
            prev = prev->next->next;
            cur = cur->next;//重点，cur指向的节点已经被交换，所以，不需要cur=cur->next->next 易错！！
        }
        head = dump->next;
        delete dump;
        return head;
    }
};