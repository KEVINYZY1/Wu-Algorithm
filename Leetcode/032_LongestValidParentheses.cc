#include<vector>
#include<stack>
using namespace std;


//暴力解法，超时
class Solution1 {
public:
    int longestValidParentheses(string s) {
        int leftWindow=0;
        int rightWindow=0;
        int result=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')')
                continue;
            stack<char>temp;
            int j=i;
            while(j<s.size()){
                if(s[j]=='(')
                    temp.push(s[i]);
                else{
                    if(!temp.empty()){
                        temp.pop();
                        if(temp.empty())
                            result=max(j-i+1,result);
                    }
                    else break;
                }
                j++;
            }
        }
        return result;
    }
};

//方法2，所有无法匹配的)都是每个有效子字符串的分界点
//使用这个方法，缺点是面对"(()"这种情况，需要额外判断，当栈内还有‘(',一个最外层完整的group还没有匹配完成
//需要通过查询下一个即将匹配还未匹配的"("的index来更新result
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;//这里使用vector实现栈，可以达到stack<pair<char,int>>的效果
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push_back(1);
            } else {
                if (stack.size() > 0 && stack[stack.size() - 1] == 1) {
                    stack[stack.size() - 1] = 2;
                } else if (stack.size() > 1 && stack[stack.size() - 1] > 1 && stack[stack.size() - 2] == 1) {
                    stack[stack.size() - 2] = stack[stack.size() - 1] + 2;
                    stack.pop_back();
                } else {
                    stack.push_back(-1);
                }
                while (stack.size() > 1 && stack[stack.size() - 1] > 1 && stack[stack.size() - 2] > 1) {
                    stack[stack.size() - 2] += stack[stack.size() - 1];
                    stack.pop_back();
                }
            }
        }
        
        int result = 0;
        for (int i = 0; i < stack.size(); i++) {
            if (stack[i] < 2) {
                continue;
            }
            result = max(result, stack[i]);
        }
        return result;
    }
};