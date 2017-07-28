#include<string>
#include<vector>
using namespace std;

/*
这一题，还是利用了双指针的解法，三个数字用三个下标表示，一个下标固定从数组由低到高移动，每次移动之后，另外两个下标来做类似于twosum的算法
关键有2个可以简化算法时间复杂度的办法
一个是，将输入数组排序，第一个数必须小于目标和，不然不存在结果
另一个是，当有连续相同的数时，i可以直接跳过，省去相同的步骤

另外还有一个改进是在双指针循环的时候，加上了判断，去掉重复的结果
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int index = 0;//不要有未初始化的值
        for (int i = 0;i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                index=i;
                break;
            }
        }
        for (int i = 0; i <= index; i++) {
            if( i > 0 && nums[i] == nums[i-1])  
                continue;//加上这句，终于不超时了。
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    k--;
                }
                else if (sum < 0) {
                    j++;
                }
                else if (sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;k--;
                    while(j<nums.size()&&nums[j]==nums[j-1])j++;
                    while(k>=0&&nums[k]==nums[k+1])k--;
                }
            }
        }
        return res;
    }
};