#include<vector>
using namespace std;


//一开始考虑贪心，不太好判断什么情况是跳不到终点
//后来发现只要遍历一遍数组就不会遗漏成功的情况
class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int len=nums.size();
        if(len<2)
            return true;
        int i=0;
        int reach=0;
        //i<=reach 很重要，表明了该点必须可以达到，才能测试该点能不能到终点
        //一旦该点无法达到，那么后面的所有点必然都无法达到
        for(;i<len-1 && i<=reach;i++){ 
            reach=max(nums[i]+i,reach);
        }
        return reach>=len-1;
    }
};