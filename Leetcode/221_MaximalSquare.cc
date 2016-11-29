#include<vector>
using namespace std;

//和第85题比，要求是正方形，瞬间简单不少。
//动态规划，dp[i][j]表示以点(i, j)为右下角的正方形的边长
//状态转移方程：dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxLengthSide=0;
        if(matrix.empty() || matrix[0].empty())
            return maxLengthSide;
        const int rows=matrix.size();
        const int columns=matrix[0].size();
        vector<vector<int>>dp(rows,vector<int>(columns,0));
        for (int i = 0; i < rows; ++i) 
            if (matrix[i][0] == '1') {
                dp[i][0] = 1; maxLengthSide = 1;
            }
        for (int j = 0; j < columns; ++j) 
            if (matrix[0][j] == '1') {
                dp[0][j] = 1; maxLengthSide = 1;
            }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < columns; ++j) {
                if (matrix[i][j] == '1') 
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                maxLengthSide = max(maxLengthSide, dp[i][j]);
            }
        }
        return maxLengthSide * maxLengthSide;
    }
};