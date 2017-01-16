#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;

//哈希表
class Solution1 {
public:
    bool wordPattern(string pattern, string str) {
        vector<string>newstr;
        string a;
        stringstream ss;
        ss<<str;
        while(ss>>a)
            newstr.push_back(a);
        if(newstr.size()!=pattern.size())
            return false;
        unordered_map<char,string>m;
        for(int i=0;i<newstr.size();i++){
            if(m.find(pattern[i])!=m.end()){
                if(m[pattern[i]]!=newstr[i])
                    return false;
            }
            else{
                for(auto it=m.begin();it!=m.end();it++)//要注意，pattern每个字符只能对应一个字符串
                    if(it->second==newstr[i])
                        return false;
                m[pattern[i]]=newstr[i];
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
};