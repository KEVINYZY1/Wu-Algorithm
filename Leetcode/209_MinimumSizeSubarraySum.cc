#include<vector>
using namespace std;

//找出数组中的一个和大于s的子数组，要求该子数组的长度最短
//方法1，O(n)复杂度，双指针法
class Solution1 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
            return 0;
        const int len=nums.size();
        int result=len+1;
        int left=0, right=0;
        int sum=0;
        while(right<len){//[left,right)
            while(right<len && sum<s){
                right++;
                sum+=nums[right-1];
            }
            while(sum>=s){
                result=min(result,right-left);
                sum-=nums[left];
                left++;
            }
        }
        if(result==len+1)
            return 0;
        else return result;
    }
};

//方法2，O(nlgn)复杂度，二分查找法
class Solution2 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
            return 0;
        const int len=nums.size();
        vector<int> sums(len+1,0);
        int sum=0;
        int result=INT_MAX;
        for(int i=1;i<len+1;i++){
            sum+=nums[i-1];
            sums[i]=sum;
        }
        for (int i=0;i<len;++i) {
            int left=i+1, right=len, t=sums[i]+s;
            while (left<=right) {
                int mid=left+(right-left)/2;
                if (sums[mid]<t) 
                    left=mid+1;
                else right=mid-1;
            }
            if (left==len+1) 
                break;
            result=min(result,left-i);
        }
        return result==INT_MAX ? 0:result;
    }
};