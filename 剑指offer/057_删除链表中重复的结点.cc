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

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5


class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
		if (pHead == nullptr)
            return nullptr;
        auto newHead = new ListNode(pHead->val - 1);
        newHead->next = pHead;
        auto lastHead = newHead;
        while (pHead != nullptr) {
            int temp = pHead->val;
            auto storePHead = pHead;
            bool isDup = false;
            pHead = pHead->next;
            while (pHead != nullptr && pHead->val == temp) {
                pHead = pHead->next;
                isDup = true;
            }
            if (isDup) {
                auto prev = storePHead;
                while (storePHead != nullptr && storePHead->val == temp) {
                    storePHead = storePHead->next;
                    delete prev;
                    prev = storePHead;
                }
                lastHead->next = pHead;
            }
            else lastHead = lastHead->next;
        }
        auto result = newHead->next;
        delete newHead;
        return result;
    }
};