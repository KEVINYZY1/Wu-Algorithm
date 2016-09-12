#include<vector>
#include<algorithm>
using namespace std;
//方法一，三次翻转即可。注：需要考虑k大于数组长度的情况
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k %nums.size();
        k=nums.size()-k;
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};