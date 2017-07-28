#include<vector>
using namespace std;

//在3Sum基础上做，算是比较笨的方法
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            //优化
            if (nums[i] * 4 > target)
                break;
            for (int j = i + 1; j < len - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {//这里要注意修改一下，应该是j>i+1
                    continue;
                }
                //优化
                if (nums[i] + nums[j] * 3 > target)
                    break;
                int k = j + 1, m = len - 1;
                while (k < m) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[m];
                    if (sum < target) {
                        k++;
                    }
                    else if (sum > target) {
                        m--;
                    }
                    else {
                        result.push_back({nums[i],nums[j],nums[k],nums[m]});
                        k++;
                        while (nums[k] == nums[k - 1])
                            k++;
                        m--;
                        while (nums[m] == nums[m + 1])
                            m--;
                    }
                }
            }
        }
        return result;
    }
};