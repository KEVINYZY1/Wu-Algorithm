#include<vector>
using namespace std;

//手上最多只能有一只股票（注意：可以在同一天卖出手上的股票然后再买进）
//贪心，基本思想是锁定一个低价，然后在价格升到局部最高点
//（即下一天的价钱就下降了）时候，抛出股票，然后把下一天较低的价钱作为买入，接着计算。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
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