#include<stack>
using namespace std;
class Queue {
public:
//用栈实现队列
    // Push element x to the back of queue.
    
    void push(int x) {
        stack2.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!stack1.empty()){stack1.pop();return;}
        while(!stack2.empty()){
            int a=stack2.top();
            stack1.push(a);
            stack2.pop();
        }
        stack1.pop();
    }

    // Get the front element.
    int peek(void) {
        if(!stack1.empty())return stack1.top();//忘了return
        while(!stack2.empty()){
            int a=stack2.top();
            stack1.push(a);
            stack2.pop();
        }
         return stack1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stack2.empty()&&stack1.empty();
    }
private:
    stack<int>stack2;
    stack<int>stack1;
};