#include<vector>
using namespace std;

//方法1，数出3种颜色的个数，直接对nums赋值，O(n)复杂度,计数排序

//方法2，改进版，数数赋值同时进行，难度较大
class Solution {
public:
//integers 0, 1, and 2 to represent the color red, white, and blue respectively
    void sortColors(vector<int>& nums) {
        const int len=nums.size();
        int i=0;
        int red=-1,white=-1,blue=-1;
        while(i<len){
            if(nums[i]==0){
                nums[++blue]=2;
                nums[++white]=1;
                nums[++red]=0;
            }
            else if(nums[i]==1){
                nums[++blue]=2;
                nums[++white]=1;
            }
            else if(nums[i]==2){
                nums[++blue]=2;
            }
            i++;
        }
    }
};

//方法3，左右指针来记录0和2，用另外一个指针遍历数组
