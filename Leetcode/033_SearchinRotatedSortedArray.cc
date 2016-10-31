#include<vector>
using namespace std;

//对一个有序且无重复的数组随机rotate，然后对该数组进行快速搜索。
//时间复杂度至少也得是O(lgn)吧
//新产生的数组特点，有两段是sorted
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int len=nums.size();
        int low=0;
        int high=len-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target){//运气不错
                return mid;
            }
            //然后注意这两种情况并列
            if(nums[mid]<nums[high]){//[mid,high]有序
                if(target>nums[mid]&&target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
            else {//if(nums[mid]>nums[low]){//[low,mid]有序
                if(target>=nums[low]&&target<nums[mid])
                    high=mid-1;
                else 
                    low=mid+1;
            }
        }
        return -1;
    }
};