#ifndef _SELECTSORT_H
#define _SELECTSORT_H
#include <vector>
using namespace std;
//选择排序 时间复杂度O(n2) 空间复杂度O(1)
//简单选择排序所需进行记录移动的操作次数较少，这一点上优于冒泡排序
void selectSort(vector<int>&nums){
    const int len=nums.size();
    size_t maxIndex=0;
    for(int i=len;i>1;--i){
        maxIndex=0;//至关重要！！没有不对
        for(int j=1;j<i;++j){
            if(nums[j]>=nums[maxIndex])maxIndex=j;//加上了等号，才是稳定排序
        }
        swap(nums[maxIndex],nums[i-1]);
    }
}
//改进版 选择排序
void improveSelectSort(vector<int>&nums){
    const int len=nums.size();
    size_t maxIndex=0;
    bool sorted=false;
    for(int i=len;i>1;--i){
        sorted=true;
        maxIndex=0;
        for(int j=1;j<i;++j){
            if(nums[j]>=nums[maxIndex])maxIndex=j;
            else sorted =false;
        }
        swap(nums[maxIndex],nums[i-1]);
        if(sorted)return;
    }
}
#endif