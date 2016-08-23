#include<cstdlib>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
//注意边界条件，比如进位之后又产生进位，以及l1，l2位数相同情况下，最高位产生进位
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1==NULL)return l2;
        if (l2==NULL)return l1;
        int curCarry=0,prevCarry=0;
        ListNode *head=l1;
        while(l1&&l2){
            prevCarry=curCarry;
            int temp=l1->val+l2->val;
            if(temp>=10)curCarry=1;
            else curCarry=0;
            temp%=10;
            l1->val=temp+prevCarry;
            if(l1->val==10){
                l1->val=0;
                curCarry++;
            }
            l1=l1->next;
            l2=l2->next;
        }
        if((l1==NULL)&&(l2==NULL)){
            ListNode*newhead=head;
            if(curCarry){
                //l1已经为NULL，再生成新节点，无法衔接给head
                //l1=new ListNode(1);
                while(head->next){
                    head=head->next;
                }
                head->next=new ListNode(1);
            }
            return newhead;
        }
        if (l1){
            l1->val+=curCarry;
            ListNode*storeL1=l1;
            while(l1->val==10){
                l1->val=0;
                l1=l1->next;
                if(l1!=NULL)l1->val++;
                else {
                    l1=storeL1;
                    while(l1->next){
                        l1=l1->next;
                    }
                    l1->next=new ListNode(1);
                    break;
                }
            }
        }
        if (l2){
            ListNode*storeL2=l2;
            l2->val+=curCarry;
            while(l2->val==10){
                l2->val=0;
                l2=l2->next;
                if(l2!=NULL)l2->val++;
                else {
                    l2=storeL2;
                    while(l2->next){
                        l2=l2->next;
                    }
                    l2->next=new ListNode(1);
                    break;
                }
            }
            //l1=l2;
            ListNode*newhead=head;
            while(head->next){
                head=head->next;
            }
            head->next=storeL2;
            return newhead;
        }
        return head;
    }
};



//错误答案，作为警示！！
class wrongSolution {
public:
//这是大数，越界了= =
//存放在链表中的数是逆序排放的
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1=0,num2=0;
        ListNode *temp=l1;
        while(temp){
            num1=num1*10+temp->val;
            temp=temp->next;
        }
        temp=l2;
        while(temp){
            num2=num2*10+temp->val;
            temp=temp->next;
        }
        num1=reverseNum(num1);
        num2=reverseNum(num2);
        int sum= num1+num2;
        ListNode *head, *cur;
        head=new ListNode(0);//因为没有默认构造函数
        //边界条件考虑
        if(sum==0)
            return head;
        cur=head;
        while(sum){
            ListNode *node=new ListNode(sum%10);
            cur->next=node;
            cur=cur->next;
            sum/=10;
        }
        cur=head;
        head=head->next;
        delete cur;//释放不需要的节点
        return head;
    }
private:
//将一个整数逆序，末尾有0将会被无视
    int reverseNum(int num){
        int result=0;
        while(num){
            result=10*result+num%10;
            num/=10;
        }
        return result;
    }
};