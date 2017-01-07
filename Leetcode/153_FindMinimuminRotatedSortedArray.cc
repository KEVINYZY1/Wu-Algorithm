#include<vector>
using namespace std;

//没有重复的数字
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return -1;
        const int len=nums.size();
        int low=0;
        int high=len-1;
        while(low<high && nums[low] >= nums[high]){
            int mid=low+(high-low)/2;
            if(mid==low)//关键
                return nums[high]<nums[low]?nums[high]:nums[low];
            if(nums[mid]>nums[high])
                low=mid;//最小值在low+1到high之间
            else high=mid;
        }
        return nums[low];
    }
};