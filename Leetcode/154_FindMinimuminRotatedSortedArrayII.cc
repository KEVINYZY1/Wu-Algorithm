#include<vector>
using namespace std;


//有重复的数在数组中
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return -1;
        const int len=nums.size();
        int low=0;
        int high=len-1;
        while(low<high && nums[low] >= nums[high]){//第二个判断可以迅速排除情况。
            int mid=low+(high-low)/2;
            //if(mid==low)//关键
            //    return nums[high]<nums[low]?nums[high]:nums[low];
            if(nums[mid]<nums[high])
                high=mid;
            else if(nums[mid]==nums[high])//关键！
                low++;
            else low=mid+1;
        }
        return nums[low];
    }
};