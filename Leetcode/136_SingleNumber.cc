#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty())
            return 0;
        const int len=nums.size();
        int result=nums[0];
        for(int i=1;i<len;i++){
            result^=nums[i];
        }
        return result;
    }
};