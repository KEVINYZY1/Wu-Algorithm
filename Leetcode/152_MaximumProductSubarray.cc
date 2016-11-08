#include<vector>
using namespace std;

//和53题很像，关键有负数，这里的区别是维护一个局部最优不足以求得后面的全局最优
/*  
累乘的最大值碰到了一个正数；或者，累乘的最小值（负数），碰到了一个负数。
所以每次要保存累乘的最大（正数）和最小值（负数）。
同时还有一个选择起点的逻辑，如果之前的最大和最小值同当前元素相乘之后，
没有当前元素大（或小）那么当前元素就可作为新的起点
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct=nums[0];
        //int minProduct=nums[0];
        assert(!nums.empty());
        int tempProductMax=nums[0];
        int tempProductMin=nums[0];
        for(int i=1; i<nums.size(); i++){
            int a=tempProductMax*nums[i];
            int b=tempProductMin*nums[i];
            tempProductMax=max(nums[i],max(a,b));
            tempProductMin=min(nums[i],min(a,b));
            maxProduct=max(maxProduct,tempProductMax);
        }
        return maxProduct;
    }
};