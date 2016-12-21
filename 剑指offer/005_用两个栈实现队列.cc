#include<stack>
using namespace std;

//用两个栈来实现一个队列，完成队列的Push和Pop操作。 
//队列中的元素为int类型。

class Solution
{
public:
    void push(int node) {
        stack2.push(node);
    }

    int pop() {
        if(!stack1.empty()){
            int temp=stack1.top();
            stack1.pop();
            return temp;
        }
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        int temp=stack1.top();
        stack1.pop();
        return temp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};