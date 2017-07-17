#include<cstdlib>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        ListNode* dum = new ListNode(-1);
        auto head = dum;
        while (pHead1 != NULL && pHead2 != NULL) {
            if (pHead1->val < pHead2->val) {
                head->next = pHead1;
                head = head->next;
                pHead1 = pHead1->next;
            } else {
                head->next = pHead2;
                head = head->next;
                pHead2 = pHead2->next;
            }
        }
        if (pHead1 != NULL) {
            head->next = pHead1;
        }
        if (pHead2 != NULL) {
            head->next = pHead2;
        }
        head = dum->next;
        delete dum;
        return head;
    }
};