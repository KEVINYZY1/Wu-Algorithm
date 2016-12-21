#include<stack>
#include<vector>
using namespace std;

//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
//（注意：这两个序列的长度是相等的）

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(popV.empty())
            return true;
        if(pushV.empty())
            return false;
        stack<int>s;
        int i=0;
        int j=0;
        s.push(pushV[i]);
        i++;
        while(!s.empty()){
            int t=s.top();
            if(t==popV[j]){
                s.pop();
                if(i<pushV.size()){
                    s.push(pushV[i]);
                    i++;
                }
                j++;
            }
            else{
                if(i<pushV.size()){
                	s.push(pushV[i]);
                	i++;
                }
                else return false;
            }
        }
        return true;
    }
};