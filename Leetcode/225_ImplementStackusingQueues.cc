#include<queue>
using namespace std;
class Stack {
public:
    //利用2个队列，保证每次进入的元素在队列的第一位
    //保证2个队列里面有一个是空的。
    void push(int x) {  
        if (queue1.empty())  
        {  
            queue1.push(x);  
            while(!queue2.empty()){  
                int tmp = queue2.front();  
                queue2.pop();  
                queue1.push(tmp);  
            }  
        }else{  
            queue2.push(x);  
            while(!queue1.empty()){  
                int tmp = queue1.front();  
                queue1.pop();  
                queue2.push(tmp);  
            }  
        }  
    }  
  
    // Removes the element on top of the stack.  
    void pop() {  
        if (!queue1.empty())  
            queue1.pop();  
        if (!queue2.empty())  
            queue2.pop();  
    }  
  
    // Get the top element.  
    int top() {  
        if (!queue1.empty())  
            return queue1.front();  
        if (!queue2.empty())  
            return queue2.front();
            return -1;
    }  
  
    // Return whether the stack is empty.  
    bool empty() {  
        return queue1.empty() && queue2.empty();  
    }  
    
private:     
    queue<int> queue1;  
    queue<int> queue2;    
};