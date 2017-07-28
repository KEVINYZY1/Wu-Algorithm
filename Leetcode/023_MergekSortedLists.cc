#include<vector>
using namespace std;
#include<cstdlib>
#include<queue>//这里定义了优先队列
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//方法1 
//用归并的方法，将lists中的每两个链表合并，直到lists被合并为一个链表。(注意，每次合并的两个链表要尽量不同)
//利用了21题的合并两个有序链表的函数，当然stl中也提供merge函数可以使用
class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> tempLists;
        if (lists.empty())
            return NULL;
        while (lists.size() != 1) {
            tempLists.clear();
            for (int i = 0; i < lists.size(); i += 2) {
                if (i + 1 == lists.size()) {
                    tempLists.push_back(lists[i]);
                    break;
                }
                tempLists.push_back(mergeTwoLists(lists[i], lists[i + 1]));
            }
            tempLists.swap(lists);
        }
        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dump = new ListNode(-1);
        ListNode* newHead;
        newHead = dump;//这里重新做时候，犯了错误，要仔细理解指针的含义
        while (l1 && l2) {
            if (l1->val < l2->val) {
                newHead->next = l1;
                l1 = l1->next;
            }
            else {
                newHead->next = l2;
                l2 = l2->next;
            }
            newHead = newHead->next;
        }
        if (l1)
            newHead->next = l1;
        else if (l2) 
            newHead->next = l2;
        newHead = dump->next;
        delete dump;
        return newHead;
    }
};

//方法2，算法导论6.5-9,利用最小优先队列来完成k路归并
//时间复杂度上，并没有方法1有优势
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dump = new ListNode(-1);
        ListNode* head = dump;
/*
stl中的priority_queue 对于基本类型的使用方法相对简单。他的模板声明带有三个参数:
priority_queue<Type, Container, Functional>
其中Type 为数据类型， Container 为保存数据的容器（相当于底层是用什么实现的），Functional 为元素比较方式。
Container 必须是用数组实现的容器，比如 vector, deque 但不能用 list.
STL里面默认用的是 vector. 比较方式默认用 operator< , 所以如果你把后面俩个参数缺省的话，
优先队列就是大顶堆，队头元素最大。        
*/
        priority_queue<ListNode*, vector<ListNode*>, newCmp> q;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                q.push(lists[i]);
        }
        while (!q.empty()) {
            head->next = q.top();
            head = head->next;
            q.pop();
            if (head->next)
                q.push(head->next);
        }
        head = dump->next;
        delete dump;
        return head;
    }
private:
//构造一个仿函数，来供优先队列使用，使该优先队列成为最小优先队列
    struct newCmp{
        bool operator()(ListNode*left,ListNode*right)const{
            if(left->val>right->val)
                return true;
            return false;
        }
    };
};