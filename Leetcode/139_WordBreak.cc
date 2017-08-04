#include<unordered_set>
#include<vector>
#include<string>
using namespace std;

//给定一个字符串和一个字典，问该字符串是否在字典中，或由字典中的单词拼接而成。
//dfs会超时，要使用dp
//一个字符串S，它的长度为N，如果S能够被“字典集合”（wordDict）中的单词拼接而成，那么所要满足的条件为：
//F(0, N) = F(0, i) && F(i, j) && F(j, N);
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty())
            return true;
        vector<bool> wordB(s.length() + 1, false);  
        wordB[0] = true;  
        for (int i = 1; i < s.length() + 1; i++) {  
            for (int j = i - 1; j >= 0; j--) {  
                if (wordB[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {  
                    wordB[i] = true;
                    break; //只要找到一种切分方式就说明长度为i的单词可以成功切分，因此可以跳出内层循环。  
                }  
            }  
        }  
        return wordB[s.length()];  
    }
};