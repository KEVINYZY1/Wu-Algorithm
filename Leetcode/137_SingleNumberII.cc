#include<vector>
using namespace std;

//其他数都出现三次
//考虑每个元素的为一个32位的二进制数，这样每一位上出现要么为1 ，要么为0。
//对数组，统计每一位上1 出现的次数count，必定是3N或者3N+1 次。
//让count对3取模，能够获得到那个只出现1次的元素该位是0还是1。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty())
            return 0;
        const int len=nums.size();
        int result = 0;  
        for(int i = 0; i<32; i++){  
            int count = 0;   
            int mask = 1<< i;  
            for(int j=0; j<len; j++){  
                if(nums[j] & mask)  
                    count++;  
            }  
          if(count %3)  
                result |= mask;  
        }  
        return result; 
    }
};
