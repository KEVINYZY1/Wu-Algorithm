#include<vector>
using namespace std;

//在一个无序数组中，找出数组排好序之后相邻元素之间的最大差值，线性时间
//假设输入的数字都是正数，并且都是32位比特位
//要求线性时间，并且输入都是在32位比特位以内，我们使用桶排序
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int len=nums.size();
        if(len<2)
            return 0;
        int minAll = *min_element(nums.begin(), nums.end());
        int maxAll = *max_element(nums.begin(), nums.end());
        double gap = ((double)(maxAll-minAll)) / (len-1);//最大差值必然不小于gap
        //维护一个桶的最大值和最小值
        vector<int> minV(len-1, INT_MAX);
        vector<int> maxV(len-1, INT_MIN);
        for(int i = 0; i < len; i ++){
            if(nums[i] != maxAll){
                int bktId = (int)((nums[i]-minAll)/gap);
                minV[bktId] = min(minV[bktId], nums[i]);
                maxV[bktId] = max(maxV[bktId], nums[i]);
            }
        }
        int ret = 0;
        int curMax = maxV[0];
        //因为一个桶内的差值最大也就是gap，所以要求的最大差值不会出现在同一个桶内
        for(int i = 1; i < len-1; i ++){
            if(minV[i] != INT_MAX){
                ret = max(ret, minV[i]-curMax);
                curMax = maxV[i];
            }
        }
        ret = max(ret, maxAll-curMax);
        return ret;
    }
};