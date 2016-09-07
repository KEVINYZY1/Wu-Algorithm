#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>parentheses;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                parentheses.push(s[i]);
            }
            else{
                if(parentheses.empty())
                    return false;
                if(parentheses.top()=='('&&s[i]==')'){
                    parentheses.pop();
                    continue;
                }
                if(parentheses.top()=='{'&&s[i]=='}'){
                    parentheses.pop();
                    continue;
                }
                if(parentheses.top()=='['&&s[i]==']'){
                    parentheses.pop();
                    continue;
                }
                return false;
            }
        }
        if(!parentheses.empty())return false;
        return true;
    }
};