#include<vector>
using namespace std;

//这一题约束最多只能买卖两次股票，并且手上最多也只能持有一支股票。
//因为不能连续买入两次股票，所以买卖两次肯定分布在前后两个不同的区间。
//以第i天为分界线，计算第i天之前进行一次交易的最大收益preProfit[i]，和第i天之后进行一次交易的最大收益postProfit[i]
//最后遍历一遍，max{preProfit[i] + postProfit[i]} (0≤i≤n-1)就是最大收益。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        const int len=prices.size();
        int maxProfit=0;
        
        vector<int>preProfit(len,0);
        vector<int>postProfit(len,0);
        
        int curMin = prices[0];
        for (int i = 1; i < len; i++) {//问题1的算法
            curMin = min(curMin, prices[i]);
            preProfit[i] = max(preProfit[i - 1], prices[i] - curMin);
        }
        
        int curMax = prices[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            curMax = max(curMax, prices[i]);
            postProfit[i] = max(postProfit[i + 1], curMax - prices[i]);
        }
        
        for (int i = 0; i < len; i++) {
            maxProfit = max(maxProfit, preProfit[i] + postProfit[i]);
        }
        
        return  maxProfit;
    }
};