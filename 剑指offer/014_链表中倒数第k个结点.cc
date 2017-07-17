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

//输入一个链表，输出该链表中倒数第k个结点。

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if (pListHead == NULL)
            return NULL;
        if (k == 0)
            return NULL;
        auto tempHead = pListHead;
        int storeK = k;
        while (tempHead && k > 0) {
            k--;
            tempHead = tempHead->next;
        }
        if (tempHead == NULL && k > 0) {
            return NULL;
        }
        while (tempHead != NULL) {
            tempHead = tempHead->next;
            pListHead = pListHead->next;
        }
        return pListHead;
    }
};