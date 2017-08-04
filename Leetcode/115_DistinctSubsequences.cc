#include<vector>
#include<string>
using namespace std;

//DP，使用二维表来储存匹配情况
//dp[0][0] = 1; // T和S都是空串.
//dp[0][1 ... S.length() - 1] = 1; // T是空串，S只有一种子序列匹配。
//dp[1 ... T.length() - 1][0] = 0; // S是空串，T不是空串，S没有子序列匹配。
//dp[i][j] = dp[i][j - 1] + (T[i - 1] == S[j - 1] ? dp[i - 1][j - 1] : 0)
class Solution {
public:
    int numDistinct(string s, string t) {//s和t的位置要注意，是t去匹配s
        if(s.empty())
            return 0;
        int count = 0;
        const int lenS=s.size();
        const int lenT=t.size();
        vector<vector<int>>dp(lenT+1,vector<int>(lenS+1,0));
        for(int i=0;i<lenS+1;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<lenT+1;i++){
            for(int j=1;j<lenS+1;j++){
                dp[i][j]=dp[i][j-1];
                if(t[i-1]==s[j-1])
                    dp[i][j]+=dp[i-1][j-1];
            }
        }
        return dp[lenT][lenS];
    }
};