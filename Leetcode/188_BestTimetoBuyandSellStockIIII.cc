#include<vector>
using namespace std;

//最多交易k次，手上最多只能持有一支股票，求最大收益。
//陷阱，就是当k大于天数时，其实就退化成 Best Time to Buy and Sell Stock II 了。
//Best Time to Buy and Sell Stock III 就是本题k=2的情况

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty())
            return 0;
        const int len=prices.size();
        int maxProfit=0;
        if(k>=len)
            return maxProfit2(prices);
        vector<vector<int>>dpLocal(len,vector<int>(k+1,0));
        vector<vector<int>>dpGlobal(len,vector<int>(k+1,0));
        for (int i = 1; i < len ; i++) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; j++) {
                dpLocal[i][j] = max(dpGlobal[i - 1][j - 1], dpLocal[i - 1][j] + diff);
                dpGlobal[i][j] = max(dpGlobal[i - 1][j], dpLocal[i][j]);
             }
        }
        return dpGlobal[len - 1][k];
    }
    
    int maxProfit2(vector<int>& prices) {
        if(prices.empty())
            return 0;
        const int len=prices.size();
        int max=0;
        for(int i=1; i<len; i++) {  
            int diff = prices[i] - prices[i-1];  
            if(diff > 0) {  
                max += diff;  
            }  
        }  
        return max;
    }
};