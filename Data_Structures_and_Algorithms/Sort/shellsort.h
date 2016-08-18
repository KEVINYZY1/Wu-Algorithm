#ifndef _SHELLSORT_H
#define _SHELLSORT_H
#include <vector>
using namespace std;
//希尔排序
//希尔排序的实质就是分组插入排序 不稳定排序
//最初建议步长选择为N/2并且对步长取半直到步长达到1
void shellSort1(vector<int>&nums){
    const int len=nums.size();
    int gap=len/2;
    while(gap>=1){
        for(int i=0;i<gap;++i){
            for(int j=i+gap;j<len;j+=gap){
                int index=j;//这里直接插入法
                while(nums[index]<nums[index-gap]){
                    swap(nums[index],nums[index-gap]);
                    --index;
                }
            }
        }
        gap/=2;
    }
}
void shellSort2(vector<int>&nums){
    int j, gap;
    const int len=nums.size();
    for (gap = len / 2; gap > 0; gap /= 2)
        for (j = gap; j < len; j++)//从数组第gap个元素开始
            if (nums[j] < nums[j - gap])//每个元素与自己组内的数据进行直接插入排序
            {
                int key = nums[j];
                int k = j - gap;
                while (k >= 0 && nums[k] > key)
                {
                    nums[k + gap] = nums[k];
                    k -= gap;
                }
                nums[k + gap] = key;
            }
}
#endif