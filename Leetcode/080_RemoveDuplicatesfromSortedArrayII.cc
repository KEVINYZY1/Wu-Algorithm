#include<vector>
using namespace std;

//方法1，可以用计数排序的方法，需要使用额外的内存空间
//方法2，更直接，直接另外构造个数组，遍历一遍即可
//方法3，当我们需要留下某个元素时，先暂时保存好，等到下一轮再覆盖，这样我们找前一个的前一个元素A[i-2]时，就不会出现A[i-2]原来的值被覆盖的情况。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=1;
        const int len=nums.size();
        if(len<=2)
            return len;
        int temp=nums[1];
        for(int i=2;i<len;i++){
            if(nums[i]!=nums[i-2]){
                nums[index++]=temp;
                temp=nums[i];
            }
        }
        nums[index++]=temp;
        return index;
    }
};