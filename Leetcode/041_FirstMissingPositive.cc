#include<vector>
using namespace std;

//要求时间复杂度O(n) 空间复杂度O(1)
//关键利用数组下标和值的映射来完成
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int len=nums.size();
        for(int i=0;i<len;){
            if(nums[i]>0 && nums[i]<=len && nums[i]!=nums[nums[i]-1])//最后一个判断防止死循环，如[1,2]
                swap(nums[i],nums[nums[i]-1]);
            else i++;
        }
        for(int i=0;i<len;i++){
            if(nums[i]!=i+1)
                return i+1;
        }
        return len+1;
    }
};