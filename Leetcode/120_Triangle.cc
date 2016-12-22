#include<vector>
using namespace std;


//关键：必须要求相邻的数字
//方法1，自顶向下进行动态规划
//DP，思路是维护到某一个元素的最小路径和，那么在某一个元素i，j的最小路径和就是它上层对应的相邻两个元素的最小路径和加上自己的值。
//递推式是sum[i][j]=min(sum[i-1][j-1],sum[i-1][j])+triangle[i][j]。
class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        vector<vector<int>>dp(triangle.begin(),triangle.end());
        const int rows=dp.size();
        for(int i=1;i<rows;i++){
            dp[i][0]+=dp[i-1][0];
            dp[i][dp[i].size()-1]+=dp[i-1][dp[i-1].size()-1];
        }
        for(int i=2;i<rows;i++){
            for(int j=1;j<dp[i].size()-1;j++){
                dp[i][j]+=min(dp[i-1][j-1],dp[i-1][j]);
            }
        }
        int result=INT_MAX;
        for(int i=0;i<dp[rows-1].size();i++){
            result=min(result,dp[rows-1][i]);
        }
        return result;
    }
};

//方法2，自底向上来动态规划，递归式只是变成下一层对应的相邻两个元素的最小路径和加上自己的
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
            return 0;
        vector<int> res (triangle.size(),0);
        for(int i=0;i<triangle.size();i++){
            res[i] = triangle[triangle.size()-1][i];
        }
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                res[j] = min(res[j],res[j+1])+triangle[i][j]; 
            }
        }
        return res[0];
    }
};