#include<vector>
using namespace std;

//在33题基础上，唯一改变是容许数组中有重复元素
//假设原数组是{1,2,3,3,3,3,3}，那么旋转之后有可能是{3,3,3,3,3,1,2}，或者{3,1,2,3,3,3,3}，这样的我们判断左边缘和中心的时候都是3，如果我们要寻找1或者2，我们并不知道应该跳向哪一半。
//解决的办法只能是对边缘移动一步，直到边缘和中间不在相等或者相遇
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int len=nums.size();
        int low=0;
        int high=len-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target){//运气不错
                return true;
            }
            //出现了low和high会和mid下标的值一样的情况
            if(nums[mid]<nums[high]){//[mid,high]有序
                if(target>nums[mid]&&target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
            else if(nums[mid]>nums[high]){//[low,mid]有序
                if(target>=nums[low]&&target<nums[mid])
                    high=mid-1;
                else 
                    low=mid+1;
            }
            else//如果一样，则high移动一下
                high--;
        }
        return false;
    }
};