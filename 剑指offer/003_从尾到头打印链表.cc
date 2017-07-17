#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
    }
};

//输入一个链表，从尾到头打印链表每个节点的值。
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        //用栈
        vector<int> res;
        if (head == NULL)
            return res;
        stack<int> s;
        while (head != NULL) {
            s.push(head->val);
            head = head->next;
        }
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
		return res;
    }
};