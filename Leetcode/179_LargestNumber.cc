#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), [](int a, int b) {
           return to_string(a) + to_string(b) > to_string(b) + to_string(a); 
        });
        if(nums[0]==0)//如果排序后第一个数是0，则直接返回0，因为后面的数只有可能是0了。
            return "0";
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res;
    }
};