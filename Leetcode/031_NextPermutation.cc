#include<vector>
using namespace std;

//全排列的字典序生成算法
//首先，关于什么是全排列不做解释。如果一个排列为A，下一个排列为A_NEXT，那么A_NEXT一定与A有尽可能长的公共前缀。
//看具体例子，一个排列为124653，如何找到它的下一个排列，因为下一个排列一定与124653有尽可能长的前缀，所以，脑洞大开一下，从后面
//往前看这个序列，如果后面的若干个数字有下一个排列，问题就得到了解决。
//方法一，迭代  同时也是stl中的实现
class Solution1 {
public:
    void nextPermutation(vector<int>& nums) {
        int first = nums.size() - 1;
        int second = first;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] <= nums[i - 1]) {//这里要求是小于等于,因为要考虑重复元素的存在
                first--;
            }
            else break;
        }
        //全排列的最后一种，则返回第一种排序
        if (first == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        while (second > 0 && nums[first - 1] >= nums[second]) {//等于号不能忘,因为要考虑重复元素的存在
            second--;
        }
        swap(nums[second], nums[first - 1]);
        reverse(nums.begin() + first, nums.end());//这里别忘了
    }
};