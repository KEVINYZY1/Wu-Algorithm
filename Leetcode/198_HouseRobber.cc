#include<vector>
using namespace std;

//数组中的最大和序列，要求序列中元素不能相邻
class Solution {
public:
    int rob(vector<int>& nums) {
        int taken = 0;
        int nontaken = 0;
        int maxprofit = 0;
        for(int i = 0; i < nums.size(); ++i) {
            taken = nums[i] + nontaken;
            nontaken = maxprofit;
            maxprofit = max(taken, nontaken);
        }
        return maxprofit;
    }
};