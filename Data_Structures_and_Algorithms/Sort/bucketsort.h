#ifndef _BUCKETSORT_H
#define _BUCKETSORT_H
#include"../Sort/quicksort.h"
#include <vector>
using namespace std;
//桶排序
//桶排序是常见排序里最快的一种,比快排还要快…大多数情况下
//桶排序非常快,但是同时也非常耗空间,基本上是最耗空间的一种排序算法
//桶排序假设序列由一个随机过程产生，该过程将元素均匀而独立地分布在区间[0,1)上。
//基本思想是：把区间[0,1)划分成n个相同大小的子区间，称为桶。将n个记录分布到各个桶中去。

//桶排序的平均时间复杂度为线性的O(N+C)，其中C=N*(logN-logM)。
//如果相对于同样的N，桶数量M越大，其效率越高，最好的时间复杂度达到O(N)。 当然桶排序的空间复杂度 为O(N+M)，
void bucketSort(vector<int>&nums){
    //输入是0~99，故分为10个桶，每个桶的元素用快排排序
    vector<vector<int> >bucket(10);
    const int len=nums.size();
    for (int i=0; i<len; ++i) {
        bucket[nums[i]/10].push_back(nums[i]);
    }
    for (int i=0;i<10;++i){
        quickSort(bucket[i]);
    }
    int k=0;
    for (int i=0;i<10;++i){
        int bucketLength=bucket[i].size();
        for(int j=0;j<bucketLength;++j){
            nums[k++]=bucket[i][j];
        }
    }
}
#endif