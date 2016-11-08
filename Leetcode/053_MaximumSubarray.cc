#include<vector>
using namespace std;

//动态规划和分治法都能做，分治法是算法导论中介绍的那种，时间复杂度过高
//和121题很类似
//注意，哪怕最大子数组和为负数，也算数
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        assert(!nums.empty());
        int tempSum=nums[0];
        maxSum=max(maxSum,tempSum);
        //只计算每个位置上，到包含这个点得最大子数组，然后用maxSum保存最大的值。
        for(int i=1; i<nums.size(); i++){//这里i是1
            if(tempSum>=0)
                tempSum+=nums[i];
            else tempSum=nums[i];
            maxSum=max(maxSum,tempSum);
        }
        return maxSum;
    }
};