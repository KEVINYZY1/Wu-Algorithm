#include<set>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
//将dict数组视为一个简单的哈希表，存放s中的字符以及该字符在遍历中最后一次出现的位置的映射关系
    int lengthOfLongestSubstring(string s) {
        vector<int>dict(256,-1);
        int start=-1;
        int maxLength=0;
        for(int i=0;i<s.size();++i){
            if(dict[s[i]]>start)//只有当s[i]已经出现过，才会为真
                start=dict[s[i]];//更改最长子字符串的开始位置
            dict[s[i]]=i;
            maxLength=max(maxLength,i-start);
        }
        return maxLength;
    }
};

class wrongSolution {
public:
//从头到尾遍历，找出每个不同的子串长度
//暴力破解，超时，时间复杂度O(n2)
    int lengthOfLongestSubstring(string s) {
        int maxLength=0;
        set<char> subString;
        const int length=s.size();
        int curLength=0;
        string temp;
        for(int i=0;i<length;++i){
            if(subString.find(s[i])==subString.end()){
                subString.insert(s[i]);
                curLength++;
                temp+=s[i];
            }
            else{
                auto index=find(temp.begin(),temp.end(),s[i]);
                int pos=index-temp.begin();
                int n=temp.size()-pos-1;
                temp=temp.substr(++pos,n);
                temp+=s[i];
                curLength=temp.size();
                subString.clear();
                for(int k=0;k<temp.size();k++){
                    subString.insert(temp[k]);
                }
            }
            maxLength=max(maxLength,curLength);
        }
        return maxLength;
    }
};