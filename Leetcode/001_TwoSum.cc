#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
// 假设一定会有正确结果，并且找到一个正确结果就返回
// 要利用哈希表保存原先输入数组下标和值的映射关系
// 要注意，输入的数组中可能有相同的数字,所以得将哈希的value设为数组来存储相同数值的不同下标
    vector<int> twoSum(vector<int>& nums, int target) {
        const int length = nums.size();
        map<int, vector<int> > mNums;
        for (int k = 0; k < length; ++k) {
            mNums[nums[k]].push_back(k);
        }
        sort(nums.begin(), nums.end());
        vector<int> result;
        int i = 0, j = length - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum < target)
                ++i;
            if (sum > target)
                --j;
            if (sum == target) {
                if (nums[i] == nums[j]) {
                    result.push_back(mNums[nums[i]][0]);
                    result.push_back(mNums[nums[i]][1]);
                } else {
                    result.push_back(mNums[nums[i]][0]);
                    result.push_back(mNums[nums[j]][0]);
                }
                if (result[0] > result[1])
                    swap(result[0], result[1]);
                return result;
            }
        }
        return result;
    }
};

// 解法更优雅
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int length = nums.size();
        map<int, vector<int> > mNums;
        vector<int> result;
        for (int i = 0; i < length; i++) {
            int another = target - nums[i];
            if mNums.find(another) {
                result.push_back(i);
                result.push_back(mNums[another];
                return result;
            }
            mNums[nums[i]] = i;
        }
        return result;
    }
}
