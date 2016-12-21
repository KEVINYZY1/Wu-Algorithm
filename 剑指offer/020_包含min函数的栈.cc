#include<stack>
using namespace std;

//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

class Solution {
public:
    void push(int value) {
        s.push(value);
        if(minS.empty())
            minS.push(value);
        else{
            auto temp=minS.top();
            if(value<=temp)
                minS.push(value);
            else minS.push(temp);
        }
    }
    void pop() {
        if(!s.empty())
        	s.pop();
        if(!minS.empty())
        	minS.pop();
    }
    int top() {
        int temp=s.top();
        return temp;
    }
    int min() {
        int temp=minS.top();
        return temp;
    }
private:
    stack<int>s;
    stack<int>minS;
};