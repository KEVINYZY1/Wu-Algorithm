#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 //在单链表中移除倒数第n个节点
 //假设n永远有效
 //由于单链表只能往后移动，所以我们用2个相距n的节点，来同时向后移动，当靠后的节点移动到末尾时，删除靠前的节点的后一个即可。
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dump=new ListNode(-1);
        dump->next=head;//自己创建一个头节点，指向函数传进来的头节点，这样方便删除
        ListNode* cur=dump, *prev=dump;
        if(head->next==NULL||head==NULL)return NULL;//因为n永远有效
        while(n){
            n--;
            cur=cur->next;
        }
        while(cur&&cur->next){
            cur=cur->next;
            prev=prev->next;
        }
        //删除prev后面的那个节点
        ListNode* temp=prev->next->next;
        delete prev->next;
        prev->next=temp;
        head=dump->next;
        delete dump;
        return head;
    }
};