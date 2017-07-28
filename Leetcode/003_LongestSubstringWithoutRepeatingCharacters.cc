#include<set>
#include<string>
#include<vector>
using namespace std;

/*最长不重复子串
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3.

Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
//将dict数组视为一个简单的哈希表，存放s中的字符以及该字符在遍历中最后一次出现的位置的映射关系
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256,-1);
        int start = -1;
        int maxLength = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (dict[s[i]] > start)//只有当s[i]已经出现过，才会为真
                start = dict[s[i]];//更改最长子字符串的开始位置
            dict[s[i]] = i;
            maxLength = max(maxLength, i - start);
        }
        return maxLength;
    }
};

/* 仔细解释上面的算法
基本思路是维护一个窗口，每次关注窗口中的字符串，在每次判断中，左窗口和右窗口选择其一向前移动。
同样是维护一个HashSet, 正常情况下移动右窗口，如果没有出现重复则继续移动右窗口
如果发现重复字符，则说明当前窗口中的串已经不满足要求，继续移动有窗口不可能得到更好的结果
此时移动左窗口，直到不再有重复字符为止
中间跳过的这些串中不会有更好的结果，因为他们不是重复就是更短。
*/


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

/*
class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        start = maxLength = 0
        usedChar = {}
        
        for i in range(len(s)):
            if s[i] in usedChar and start <= usedChar[s[i]]:
                start = usedChar[s[i]] + 1
            else:
                maxLength = max(maxLength, i - start + 1)

            usedChar[s[i]] = i

        return maxLength
*/