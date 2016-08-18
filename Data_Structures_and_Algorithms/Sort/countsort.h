#ifndef _COUNTSORT_H
#define _COUNTSORT_H
#include <vector>
using namespace std;
//计数排序
//建立在已知输入序列数值范围的基础上
/*
 算法的步骤如下：
 1.找出待排序的数组中最大和最小的元素
 2.统计数组中每个值为i的元素出现的次数，存入数组C的第i项
 3.对所有的计数累加（从count中的第一个元素开始，每一项和前一项相加）
 4.反向填充目标数组：将每个元素i放在新数组的第count(i)项，每放一个元素就将count(i)减去1
 */
void countSort(vector<int>&nums){
    //由于输入在0~99，所以直接设个大小为100的数组，即可保存。
    //但如果输入范围不那么方便，考虑用哈希建立key-count的映射关系
    vector<int>count(100,0);
    const int len=nums.size();
    for(int i=0;i<len;++i){
        ++count[nums[i]];
    }
    //并非正统的计数排序
    int k=0;
    for(int i=0;i<100;++i){
        while(count[i]>0){
            nums[k++]=i;
            --count[i];
        }
        if(k==len)break;
    }
}
#endif