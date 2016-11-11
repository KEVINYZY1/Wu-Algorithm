#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//链表版的rotate
//要考虑k大于链表长度的情况
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)//这里是为了防止链表长度为0，然后k对0取余数，会中断
            return head;
        ListNode* kthHead=head, *tempHead=head; 
        //考虑一下链表长度不够k
        int lenList=0;
        while(tempHead){
            tempHead=tempHead->next;
            lenList++;
        }
        if(lenList<k)
            k%=lenList;
        if(lenList==k)
            return head;
        //找到第k个结点，双指针
        tempHead=head;
        while(tempHead && k--){
            tempHead=tempHead->next;
        }
        while(tempHead){
            tempHead=tempHead->next;
            kthHead=kthHead->next;
        }
        //开始三次逆转
        tempHead=head;
        while(tempHead->next!=kthHead){
            tempHead=tempHead->next;
        }
        auto newKthHead=reverseList(kthHead);
        tempHead->next=NULL;
        auto newHead=reverseList(head);
        tempHead=newHead;
        while(tempHead->next){
            tempHead=tempHead->next;
        }
        tempHead->next=newKthHead;
        return reverseList(newHead);
    }
private:
//逆转单链表
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        while(head){
            auto temp=head->next;
            head->next=prev;//注意顺序
            prev=head;
            head=temp;
        }
        return prev;
    }
};