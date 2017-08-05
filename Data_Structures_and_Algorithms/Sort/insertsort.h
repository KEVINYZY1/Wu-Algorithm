#ifndef _INSERTSORT_H
#define _INSERTSORT_H
#include <vector>
using namespace std;
//插入排序 时间复杂度O(n2) 空间复杂度O(1)
//待插入前一部分的数组是sorted的，这点很关键
//直接插入排序适合记录数比较少、给定序列基本有序的情况
//直接插入排序是一种稳定的原地排序算法
void insertSort(vector<int>&nums) {
    const int len = nums.size();
    int key = 0;
    int j;
    for(int i = 1; i < len; ++i) {
        key = nums[i];
        for (j = i-1; j >= 0; --j) {
            if (nums[j] > key)
                nums[j+1] = nums[j];
            else break;
            //if(nums[j]>nums[j+1]){
            //    swap(nums[j],nums[j+1]);
            //}用赋值代替了交换，好一点
        }
        nums[j + 1] = key;
    }
}
//折半插入排序
//折半插入排序是对直接插入排序的一种改进，这种改进只考虑了关键字比较次数，并没有减少移位次数
//记录数较小、待排序序列基本有序情况下直接插入排序优于折半插入排序。此外，折半插入排序是不稳定的原地排序，实现起来也较复杂
int binarysearch(vector<int>&nums, int low, int high, int target) {
    while (low < high) {
        int mid = low + (high-low) * 0.5;
        if (nums[mid] < target)
            low = mid + 1;
        else if (nums[mid] > target)
            high = mid - 1;
        else if (nums[mid] == target)
            return mid;
    }
    return (nums[low] > target) ? low : low + 1;
}
void binaryInsertSort(vector<int>& nums) {
    const int len = nums.size();
    int key = 0;
    int i, j;
    for (i = 1; i < len; ++i) {
        key = nums[i];
        int insertIndex = binarysearch(nums, 0, i-1, key);
        if (insertIndex <= i-1) {
            for (j = i; j > insertIndex; --j)
                nums[j] = nums[j-1];
            nums[insertIndex] = key;
        }
    }
}
#endif