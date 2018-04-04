#include <string>
#include <cassert>
#include <stack>
#include <iostream>
using namespace std;

class Stack {
public:
    int getMin() {
        return storeMin_.top();
    }

    void push(int val) {
        data_.push(val);
        if (!storeMin_.empty()) {
            if (val < storeMin_.top()) {
                storeMin_.push(val);
            } else {
                storeMin_.push(storeMin_.top());
            }
        } else {
            storeMin_.push(val);
        }
    }

    int pop() {
        int top = data_.top();
        data_.pop();
        storeMin_.pop();
        return top;
    }

private:
    stack<int> data_;
    stack<int> storeMin_;
};

int main() {
    Stack s;
    s.push(3);
    assert(s.getMin() == 3);
    s.push(5);
    s.pop();
    assert(s.getMin() == 3); 
}