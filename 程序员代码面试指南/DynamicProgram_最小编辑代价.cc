#include <string>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
str1通过删除、插入和替换三种操作来转换成str2，每种操作都有特定的代价，转换的最小代价
*/

class Solution {
public:
    Solution(int ins = 5, int del = 3, int rep = 2) {
        insertCost_ = ins;
        deleteCost_ = del;
        replaceCost_ = rep;
    }

    int minCost(string str1, string str2) {
        const int len1 = str1.size();
        const int len2 = str2.size();
        //dp[i][j] 代表str1前i个字符串转换成str2前i个字符串的最小代价
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1));
        //初始化dp数组
        for (int i = 1; i <= len1; ++i) {
            dp[i][0] = dp[i - 1][0] + deleteCost_;
        }
        for (int i = 1; i <= len2; ++i) {
            dp[0][i] = dp[0][i] + insertCost_;
        }
        //dp循环
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i -1][j - 1] + replaceCost_;
                }
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + insertCost_);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + deleteCost_);
            }
        }
        return dp[len1][len2];
    }
    
private:
    int insertCost_;
    int deleteCost_;
    int replaceCost_;
};

int main() {
    Solution s;
    
}