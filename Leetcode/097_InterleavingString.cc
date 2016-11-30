#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int len1=s1.size();
        const int len2=s2.size();
        const int len3=s3.size();
        if(len1+len2 != len3)
            return false;
    
        //bool的二维数组动态申请
        
        //bool **dp=new bool *[len1+1];
        //for(int i=0; i<len1+1; i++){
        //    dp[i]=new bool [len2+1];//这样申请的空间不是连续的= =
        //}这样申请等二维数组，需要先释放指针数组的每个元素指向的数组，然后再释放该指针数组dp
        
        vector<vector<bool> > dp(1 + len1, vector<bool>(1 + len2, true));
        for (int i = 1; i <= len1; ++i) {
            dp[i][0] = s1[i - 1] == s3[i - 1] && dp[i - 1][0];
        }
        for (int i = 1; i <= len2; ++i) {
            dp[0][i] = s2[i - 1] == s3[i - 1] && dp[0][i - 1];
        }
        for (int i1 = 1; i1 <= len1; ++i1) {
            for (int i2 = 1; i2 <= len2; ++i2) {
                bool case1 = s1[i1 - 1] == s3[i1 + i2 - 1] && dp[i1 - 1][i2];
                bool case2 = s2[i2 - 1] == s3[i1 + i2 - 1] && dp[i1][i2 - 1];
                dp[i1][i2] = case1 || case2;
            }
        }

        return dp[len1][len2];
    }
};