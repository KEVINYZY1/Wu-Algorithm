#ifndef _RADIXSORT_H
#define _RADIXSORT_H
#include <vector>
#include <array>
using namespace std;
//基数排序
//创建各个位的桶，然后从低位到高位开始比较。
//每个位的排序，由于只有0~9进行排序，故采用计数排序的方法比较合适

//返回nums数组中数字的最高位是多少
int findMaxBit(vector<int>&nums){
    const int len=nums.size();
    int k=10,maxBit=1;
    for (int i=0; i<len; ++i) {
        while(nums[i]>=k){
            k*=10;
            ++maxBit;
        }
    }
    return maxBit;
}
void radixSort(vector<int>&nums){
    const int len=nums.size();
    vector<int>temp(len,0);
    array<int,10>count;
    int maxBit=findMaxBit(nums);
    int i,j,k;int radix=1;
    for(i=1;i<=maxBit;++i){
        //每个循环都要初始化count数组
        for(j=0;j<10;++j){
            count[j]=0;
        }
        //计数排序
        for(j=0;j<len;++j){
            k=(nums[j]/radix)%10;
            ++count[k];
        }
        for(j=1;j<10;++j){
            count[j]+=count[j-1];
        }
        //务必要注意赋值次序问题，降序将nums数组中数按着某一位的大小赋值给temp数组。！！！！
        //这样可以保持nums数组中原来按更低位排出由小到大的次序不变
        for(j=len-1;j>=0;--j){
            k=(nums[j]/radix)%10;
            temp[count[k]-1]=nums[j];
            --count[k];
        }
        for(j=0;j<len;++j){
            nums[j]=temp[j];
        }
        radix*=10;
    }
}
#endif