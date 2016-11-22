#include<string>
using namespace std;

//方法1，递归，会超时
class Solution1 {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        count=0;
        findDecodingWay(s,0);
        return count;
    }
private:
    int count;
    void findDecodingWay(string &s, int decodeIndex){
        if(decodeIndex==s.size()){
            count++;
            return;
        }
        if(s[decodeIndex]=='0')//注意处理0这个情况
            return;
        if(decodeIndex<s.size()-1){
            if(s[decodeIndex]=='1')
                findDecodingWay(s,decodeIndex+2);
            else if(s[decodeIndex]=='2' && s[decodeIndex+1]<'7')//注意2后面的需要小于等于6
                findDecodingWay(s,decodeIndex+2);
        }
        findDecodingWay(s,decodeIndex+1);
    }
};

//方法2，DP
//由于只要求计算最多的解码方法而并不要求每种解码的结果，所以用DP做更为合适高效。
class Solution2 {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        if(s[0]<'1' ||s[0]>'9')
            return 0;
        vector<int> dp(s.size()+1,0);
        dp[0] = dp[1] = 1;
        for(int i=1; i<dp.size(); i++){
            assert(s[i]>='0' || s[i]<='9');
            int v = (s[i-1]-'0')*10 + (s[i]-'0');
            if(v<=26 && v>9) 
                dp[i+1] += dp[i-1];
            if(s[i]!='0') 
                dp[i+1] += dp[i];
            if(dp[i+1]==0) 
                return 0;
        }
        return dp[s.size()];
    }
};