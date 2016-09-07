#include<vector>
using namespace std;
#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//用归并的方法，将lists中的每两个链表合并，直到lists被合并为一个链表。(注意，每次合并的两个链表要尽量不同)
//利用了21题的合并两个有序链表的函数，当然stl中也提供merge函数可以使用
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>tempLists;
        if(lists.empty())
            return NULL;
        while(lists.size()!=1){
            tempLists.clear();
            for(int i=0;i<lists.size();i+=2){
                if(i+1==lists.size()){
                    tempLists.push_back(lists[i]);
                    break;
                }
                tempLists.push_back(mergeTwoLists(lists[i],lists[i+1]));
            }
            tempLists.swap(lists);
        }
        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dump=new ListNode(-1);
        ListNode* newHead;
        newHead=dump;//这里重新做时候，犯了错误，要仔细理解指针的含义
        while(l1&&l2){
            if(l1->val<l2->val){
                newHead->next=l1;
                l1=l1->next;
            }
            else{
                newHead->next=l2;
                l2=l2->next;
            }
            newHead=newHead->next;
        }
        if(l1)newHead->next=l1;
        else if(l2)newHead->next=l2;
        newHead=dump->next;
        delete dump;
        return newHead;
    }
};