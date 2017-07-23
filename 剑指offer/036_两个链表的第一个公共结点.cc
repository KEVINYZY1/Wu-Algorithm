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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL)
            return NULL;
        auto storepHead1 = pHead1;
        auto storepHead2 = pHead2;
        int len1 = 1;
        while (pHead1->next) {
            pHead1 = pHead1->next;
            len1++;
        }
        int len2 = 1;
        while (pHead2->next) {
            pHead2 = pHead2->next;
            len2++;
        }
        if (pHead1 != pHead2)
            return NULL;
        pHead1 = storepHead1;
        pHead2 = storepHead2;
        if (len2 > len1) {
            int diff = len2 - len1;
            while (diff) {
                diff--;
                pHead2 = pHead2->next;
            }
        } else {
            int diff = len1 - len2;
            while (diff) {
                diff--;
                pHead1 = pHead1->next;
            }
        }
        while (pHead1 && pHead2) {
            if (pHead1 == pHead2)
                break;
            pHead2 = pHead2->next;
            pHead1 = pHead1->next;
        }
        return pHead1;
    }
};