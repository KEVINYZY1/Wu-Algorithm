#include<cstdlib>

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        auto pHead = head;
        if (pHead == NULL)
            return NULL;
        //每个结点后面加一个
        auto storepHead = pHead;
        while (pHead != NULL) {
            auto temp = pHead->next;
            pHead->next = new RandomListNode(pHead->label);
            pHead->next->next = temp;
            pHead = pHead->next->next;
        }
        pHead = storepHead;
        while (pHead != NULL) {
            if (pHead->random != NULL)//随机指针有可能为空，真是害人
            	pHead->next->random = pHead->random->next;
            pHead = pHead->next->next;
        }
        //再把链表拆开
        pHead = storepHead;
        auto newHead = pHead->next;
        while (pHead != NULL) {
            auto temp = pHead->next;
            pHead->next = pHead->next->next;
            pHead = pHead->next;
            if (pHead != NULL)
                temp->next = pHead->next;
        }
        return newHead;
    }
};