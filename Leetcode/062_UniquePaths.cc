#include<vector>
using namespace std;

//方法1，回溯法，超时
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;  
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1); 
    }
};

//方法2，动态规划，建立一个m*n的表
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j <n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};