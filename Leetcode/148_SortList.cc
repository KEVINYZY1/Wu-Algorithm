#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//单链表排序
//要求时间复杂度为O(n log n)，空间复杂度O(1)。则不能使用桶排序。

//方法一，用递归版本的归并排序
class Solution1 {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        return mergeSort(head);
    }
private:
    ListNode* mergeSort(ListNode* head){
        if(!head||!head->next)return head;
        ListNode*slow=head,*fast=head,*p;
        while(fast&&fast->next){
            p=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        p->next=NULL;
        ListNode *middle=slow;//分成2条链表
        //由于对链表理解不够，还是没想好怎么划分2个链表
        ListNode *newHead;
        if(middle!=head){
            ListNode *head1=mergeSort(head);
            ListNode *head2=mergeSort(middle);
            newHead =mergeList(head1,head2);
        }
        return newHead;
    }
    //空间复杂度O(1)情况下，将2个已经排好序的链表按大小顺序合并
    //另外，这也是leetcode的21题
    ListNode* mergeList(ListNode* head1,ListNode*head2) {
        ListNode *dump=new ListNode(-1);
        ListNode *newHead=dump;
        while(head1&&head2){
            if(head1->val<head2->val){
                newHead->next=head1;
                head1=head1->next;
            }
            else{
                newHead->next=head2;
                head2=head2->next;
            }
            newHead=newHead->next;
        }
        if(!head1){
            newHead->next=head2;
        }
        else{
            newHead->next=head1;
        }
        newHead=dump->next;
        delete dump;
        return newHead;
    }
};

//方法二，根据stl中std::list.sort的源码，使用归并排序的迭代版本
