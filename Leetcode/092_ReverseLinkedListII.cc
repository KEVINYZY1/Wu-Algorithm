#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 //逆转链表中特定的某一部分
 //假设m和n输入是有效的
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* start,*end;
        ListNode* dump=new ListNode(-1);
        dump->next=head;
        int x=0;
        ListNode*tempDump=dump;
        while(tempDump){
            if(x==m-1)
                start=tempDump;
            if(x==n){
                end=tempDump;
                break;
            }
            tempDump=tempDump->next;
            x++;
        }
        ListNode*prev=end->next;
        //重要！！！本来以为end->next是不会变的，结果测试不通过，必须要储存end—>next的值才行。
        //但是为什么呢，我在循环中也没有影响到end指针的值，按理说，应该不会改变end->next
        //网上的解法是用for循环，m-n次循环即可。
        ListNode*tempEnd=end->next;
        ListNode*newHeadBetween=start->next;
        while(newHeadBetween!=tempEnd){
            ListNode*temp=prev;
            prev=newHeadBetween;
            newHeadBetween=newHeadBetween->next;
            prev->next=temp;
        }
        start->next=prev;
        head=dump->next;
        delete dump;
        return head;
    }
};