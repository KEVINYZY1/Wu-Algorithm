#include<vector>
using namespace std;


//方法1，递归
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        const int len=nums.size();
        return findIndex(0,len-1,nums,target);
    }
private:
    int findIndex(int low,int high,vector<int>& nums, int target){
        int mid=low+(high-low)/2;
        if(low==high&&nums[high]!=target){
            if((high==nums.size()-1) && (nums[high]<target))
                ++high;
            return high;
        }
        if(nums[mid]>target){
            return findIndex(low,mid,nums,target);//别忘了return
        }
        else if(nums[mid]<target){
            return findIndex(mid+1,high,nums,target);
        }
        else if(nums[mid]==target){
            return mid;
        }
        return -1;
    }
};

//方法2，更为推荐。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();  
        int low = 0;  
        int high = n -1;  
        int mid;  
        while(low <= high)  {   
            mid=low+(high-low)/2;  
            if(target==nums[mid])  
                return mid;  
            else if(target<nums[mid])  
                high=mid-1;  
            else   
                low=mid+1;  
        }  
        return low;
    }
};
