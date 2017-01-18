#include<string>
using namespace std;

//对给出的字符串s，在s前面加最短的字符串，使新字符串是回文
//方法1，暴力破解 超时！！！
//新的回文串的中心肯定在s里面，故s以第一个字符为起点，必然存在一个回文串，哪怕该回文串长度是1
//故找到原字符串中以第一个字符为起点最长的回文串，然后就是把剩余部分的翻转补充到原字符串头部即可
class Solution {
public:
    string shortestPalindrome(string s) {
        string result;
        if(s.empty())
            return result;
        const int len=s.size();
        for(int i=len;i>=2;i--){
            if(isPalindrome(s,0,i)){
                string temp=s.substr(i,len-i);
                reverse(temp.begin(), temp.end());
                return temp+s;
            }
        }
        string temp=s.substr(1,len-1);
        reverse(temp.begin(), temp.end());
        return temp+s;
    }
private:
    bool isPalindrome(string s, int start, int end){
        for(int i=0; i<(end-start)/2; i++){
            if(s[start+i]!=s[end-1-i])
                return false;
        }
        return true;
    }
};

//方法2，todo，类似于KMP
class Solution {
public:
    string shortestPalindrome(string s) {
        string result;
        if(s.empty())
            return result;
            
        string r = s;
        reverse(r.begin(), r.end());
        string t = s+"#"+r;
        //新字符串t中最长公共前缀后缀长度，使用next数组
        vector<int> next(t.size(), 0);//next[i]表示从t[i]到开头的子串的相同前缀后缀的个数
        for (int i=1; i<t.size(); ++i) {
            int j=next[i-1];
            while (j>0 && t[i]!=t[j]) 
                j=next[j-1];
            next[i]=(j+=t[i]==t[j]);
        }
        return r.substr(0, s.size() - next.back()) + s;
    }
};