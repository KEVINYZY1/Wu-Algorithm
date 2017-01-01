#include<vector>
using namespace std;

//假设num[i] ≠ num[i+1]以及num[-1] = num[n] = -∞ 寻找数组中的peak值
//方法1，遍历，反正注定存在
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())
            return 0;
        const int len =nums.size();
        bool leftOk=true;
        for(int i=0;i<len-1;i++){
            if(leftOk && nums[i]>nums[i+1])
                return i;
            else if(nums[i]>nums[i+1]){
                leftOk=false;
            }
        }
        return len-1;
    }
};

//方法2，反正只要找一个peak下标就ok
//由题意可知因为两端都是负无穷，有上坡就必定有一个峰，我们看中点的左右两边大小，如果向左是上坡，就抛弃右边，如果向右是上坡，就抛弃左边。直到两边都小于中间，就是峰了。
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())
            return 0;
        const int len =nums.size();
        int left=0,right=len-1;  
        while(left<right){  
            int mid=(left+right)/2;  
            if(nums[mid]<nums[mid+1])  
                left=mid+1;  
            else  
                right=mid;  
        }
        return left;
    }
};