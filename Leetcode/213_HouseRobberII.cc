#include<vector>
using namespace std;


//和上一题的不同是，这一次是循环数组，首尾相连。这样的话，抢了第一家就不能抢最后一家了。
//那干脆解法就是分别去掉第一家和最后一家，然后求能抢的最大值，比较一下，得出最后结果
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int a=rob(nums,0,nums.size()-1);
        int b=rob(nums,1,nums.size());
        return a>b? a:b;
    }
private:    
    int rob(vector<int>& nums, int start, int end){
        int notRob=0;
        int rob=0;
        int result=0;
        for(int i=start; i<end; i++){
            rob=notRob+nums[i];
            notRob=result;
            result=max(rob,notRob);
        }
        return result;
    }
};