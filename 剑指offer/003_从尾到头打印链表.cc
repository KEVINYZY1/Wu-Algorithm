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

//输入一个链表，从尾到头打印链表每个节点的值。
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>result;
        if(head==NULL)
            return result;
        vector<ListNode *> node;
        auto temp=head;
        while(temp!=NULL){
			node.push_back(temp);
            temp=temp->next;
        }
        for(int i=node.size()-1;i>=0;i--){
            result.push_back(node[i]->val);
        }
        return result;
    }
};