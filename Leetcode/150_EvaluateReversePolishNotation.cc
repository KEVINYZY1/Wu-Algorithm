#include<string>
#include<stack>
#include<vector>
using namespace std;

//假设输入的都是符合题目要求的tokens
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty())
            return 0;
        const int len=tokens.size();
        stack<string>s;
        for(int i=0;i<len;i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                s.push(tokens[i]);
            }
            else{
                if(tokens[i]=="+"){
                    int a=stoi(s.top());
                    s.pop();
                    int b=stoi(s.top());
                    s.pop();
                    s.push(to_string(a+b));
                }
                if(tokens[i]=="-"){
                    int a=stoi(s.top());
                    s.pop();
                    int b=stoi(s.top());
                    s.pop();
                    s.push(to_string(b-a));
                }
                if(tokens[i]=="*"){
                    int a=stoi(s.top());
                    s.pop();
                    int b=stoi(s.top());
                    s.pop();
                    s.push(to_string(a*b));
                }
                if(tokens[i]=="/"){
                    int a=stoi(s.top());
                    s.pop();
                    int b=stoi(s.top());
                    s.pop();
                    s.push(to_string(b/a));
                }
            }
        }
        return stoi(s.top());
    }
};