#include<vector>
using namespace std;
#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//leetcode中得两道逆转链表题是这一题的预热
//将链表中每k个节点为一组逆序，最后若不满k节点则不操作
class Solution1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> lists;
        lists.push_back(head);
        int count = k;
        while (head) {
            head = head->next;
            count--;
            if (count == 1) {
                if (head == NULL)
                    break;
                lists.push_back(head->next);
                head->next = NULL;
                head = lists[lists.size() - 1];
                count = k;
            }
        }
        //至此，链表被拆分为k个元素一组的单链表，放在链表数组lists中
        for (int i = 0; i < lists.size() - 1; ++i) {
            lists[i] = reverse(lists[i]);
        }
        //判断最后一个链表是否有k个，有的话，则也要逆序
        int tempCount = 0;
        ListNode* tempHead = lists[lists.size() - 1];
        while (tempHead) {
            tempHead = tempHead->next;
            tempCount++;
        }
        if (tempCount == k) {
            lists[lists.size() - 1] = reverse(lists[lists.size() - 1]);
        }
        //合并链表数组
        tempHead = lists[0];
        for (int i = 0; i < lists.size() - 1; ++i) {
            while (tempHead->next) {
                tempHead = tempHead->next;
            }
            tempHead->next = lists[i + 1];
        }
        return lists[0];
    }
private:
    ListNode* reverse(ListNode* head) { 
        ListNode* prev = NULL;
        while (head) {
            ListNode* temp = prev;
            prev = head;
            head = head->next;
            prev->next = temp;
        }
        return prev;
    }
};

//方法二，针对方法一进行了优化，去除一些不必要的步骤
class Solution2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) 
            return head;
        ListNode *node = head, *first = head, *prev = NULL, *next = NULL;
        for (int count = 1; node; ++count, node = next) {
            next = node->next;
            if (count != k) 
                continue;
            reverse(first, next);
            if (prev)
                prev->next = node;
            else
                head = node;
            prev = first;
            first = next;
            count = 0;
        }
        return head;
    }
private:
//灵活使用逆转链表
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail;
        while(head) {
            ListNode* temp = prev;
            prev = head;
            head = head->next;
            prev->next = temp;
        }
        return prev;
    }
};