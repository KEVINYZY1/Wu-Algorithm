#ifndef _BUBBLESORT_H
#define _BUBBLESORT_H
#include <vector>
using namespace std;
//冒泡排序 时间复杂度O(n2) 空间复杂度O(1)
void bubbleSort(vector<int>&nums){
    const int len=nums.size();
    for(int i=len;i>1;--i){
        for(int j=0;j<i-1;++j){
            if(nums[j]>nums[j+1]){//这里不加等号，决定了是不是稳定排序
                swap(nums[j],nums[j+1]);
            }
        }
    }
}
//改进版 冒泡排序
//如果有一次冒泡中，没有元素发生交换，则默认sorted，直接返回函数
void improveBubbleSort(vector<int>&nums){
    const int len=nums.size();
    bool swapped=true;
    for(int i=len;i>1;--i){
        swapped=false;
        for(int j=0;j<i-1;++j){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                swapped=true;
            }
        }
        if(!swapped)return;
    }
}
#endif