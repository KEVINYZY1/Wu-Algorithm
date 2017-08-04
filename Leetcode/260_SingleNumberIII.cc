#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        if (nums.empty())
            return result;
        //先异或遍历数组
        const int len = nums.size();
        int num = nums[0];
        for (int i = 1; i < len; i++) {
            num ^= nums[i];
        }
        //确定num从右边开始，第一个有1的比特位
        int base = 1;
        int temp = num & base;
        while (temp == 0) {
            base = base << 1;
            temp = num & base;
        }
        //按该比特位base，分别异或
        bool first = false;
        bool second = false;
        int num1, num2;
        for (int i = 0; i < len; i++) {
            if ((nums[i]) & base) {
                if (!first) {
                    num1 = nums[i];
                    first = true;
                } else {
                    num1 ^= nums[i];
                }
            } else {
                if (!second) {
                    num2 = nums[i];
                    second = true;
                } else {
                    num2 ^= nums[i];
                }
            }
        }
        result.push_back(num1);
        result.push_back(num2);
        return result;
    }
};