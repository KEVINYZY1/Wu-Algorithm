#include<string>
#include<vector>
using namespace std;

//Dfs
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        if(s.empty())
            return result;
        helper(result,vector<string>(),s,0);
        return result;
    }
private:
    void helper(vector<vector<string>> &result, vector<string> temp, string s, int i){
        const int len=s.size();
        if(i==len){
            result.push_back(temp);
            return;
        }
        for(int j=1;j<len-i+1;j++){
            string tempS=s.substr(i,j);
            if(isPalindrome(tempS)){
                temp.push_back(tempS);
                helper(result,temp,s,i+j);
                temp.pop_back();//回溯
            }
            else continue;    
        }
    }
    bool isPalindrome(string &s){
        if(s.empty())
            return true;
        const int len=s.size();
        for(int i=0;i<len/2;i++){
            if(s[i]!=s[len-1-i])
                return false;
        }
        return true;
    }
};