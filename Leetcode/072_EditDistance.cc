#include<string>
#include<vector>
using namespace std;

//算法导论中原题
//插入、交换和删除字母三种方法
//假设dp[i-1][j-1]表示一个长为i-1的字符串str1变为长为j-1的字符串str2的最短距离
class Solution {
public:
    int minDistance(string word1, string word2) {
        int minSteps=0;
        const int len1=word1.size();
        const int len2=word2.size();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        //初始化空字符串的情况
        for(int i=1; i<=len1; i++)
            dp[i][0]=i;
        for(int i=1; i<=len2; i++)
            dp[0][i]=i;
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                //增加操作：str1a变成str2后再加上b，得到str2b
                int insertion=dp[i][j-1]+1;
                //删除操作：str1a删除a后，再由str1变为str2b
                int deletion=dp[i-1][j]+1;
                //替换操作：先由str1变为str2，然后str1a的a替换为b，得到str2b
                int replace=dp[i-1][j-1]+(word1[i-1] == word2[j-1] ? 0 : 1);
                //三者取最小
                dp[i][j]=min(replace, min(insertion, deletion));
            }
        }
        return dp[len1][len2];
    }
};