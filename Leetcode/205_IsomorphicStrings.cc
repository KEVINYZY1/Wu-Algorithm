#include<string>
#include<map>
using namespace std;

//判断两个字符串是否是相类似的
//相似的题目290题
//Given "egg", "add", return true.
//Given "foo", "bar", return false.
//Given "paper", "title", return true.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        map<char,char>m;
        for(size_t i=0;i<s.size();++i){
            if(m.find(s[i])==m.end())
                m[s[i]]=t[i];
            else if(m[s[i]]!=t[i])
                return false;
        }
        m.clear();
        for(size_t i=0;i<s.size();++i){
            if(m.find(t[i])==m.end())
                m[t[i]]=s[i];
            else if(m[t[i]]!=s[i])
                return false;
        }
        return true;
    }
};