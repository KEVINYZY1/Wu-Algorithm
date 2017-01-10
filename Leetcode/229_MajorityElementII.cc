#include<vector>
using namespace std;

//如果是多于占据了三分之一数组的数呢，这种数最多有2个
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        const int len=nums.size();
        int m = 0, n = 0, cm = 0, cn = 0;
        for (auto &a : nums) {
            if (a == m) 
                ++cm;
            else if (a ==n) 
                ++cn;
            else if (cm == 0) 
                m = a, cm = 1;
            else if (cn == 0) 
                n = a, cn = 1;
            else --cm, --cn;
        }
        cm = cn = 0;
        //重新验证一下
        for (auto &a : nums) {
            if (a == m) ++cm;
            else if (a == n) ++cn;
        }
        if (cm > nums.size()/3) 
            result.push_back(m);
        if (cn > nums.size()/3) 
            result.push_back(n);
        return result;
    }
};