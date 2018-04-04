#include <string>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
从左上角开始走，只能向下或者向右。
正加负减，求得的值不能为负。
问初始值最少多少。
*/

class Solution {
public:
    int minStartValue(vector<vector<int> > matrix) {
        const int rows = matrix.size();
        const int columns = matrix[0].size();
        vector<vector<int> > dp(rows, vector<int> (columns));
        //初始化dp数组
        dp[rows - 1][columns - 1] = matrix[rows - 1][columns - 1] * -1;
        for (int i = rows - 2; i >= 0; --i) {
            dp[i][columns - 1] = dp[i + 1][columns - 1] - matrix[i][columns - 1];
        }
        for (int i = columns - 2; i >= 0; --i) {
            dp[rows - 1][i] = dp[rows - 1][i + 1] - matrix[rows - 1][i];
        }
        //dp
        for (int i = rows - 2; i >= 0; --i) {
            for (int j = columns - 2; j >= 0; --j) {
                if (dp[i + 1][j] > dp[i][j + 1]) {
                    dp[i][j] = dp[i][j + 1] - matrix[i][j];  
                } else {
                    dp[i][j] = dp[i + 1][j] - matrix[i][j]; 
                }
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution s;
    
}