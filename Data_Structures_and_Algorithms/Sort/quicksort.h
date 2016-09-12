#ifndef _QUICKSORT_H
#define _QUICKSORT_H
#include <vector>
using namespace std;
//快速排序
//分区函数，对nums[start……end-1]分区，选择第一个元素为主元，最后返回主元的下标
int partition(vector<int>&nums,int start,int end){
    int pivotIndex=start;
    int pivot=nums[pivotIndex];
    int storeIndex=pivotIndex+1;
    for (int i=pivotIndex+1; i<end; ++i) {
        if(nums[i]<pivot){
            swap(nums[i],nums[storeIndex]);
            ++storeIndex;
        }
    }
    swap(nums[pivotIndex],nums[storeIndex-1]);//这里storeIndex要减1
    return storeIndex-1;
}
//按算法导论所说，增加Hoare-Partition算法
int hoarePartition(vector<int>&nums,int start,int end){
    int pivot=nums[start];
    start++;
    end--;
    while(true){
        while(nums[start]<pivot){
            start++;
        }
        while(nums[end]>pivot){
            end--;
        }
        if(start>end){
            return start;
        }
        else 
            swap(nums[end],nums[start]);
        start++;
        end--;
    }
}
void quickSort(vector<int>&nums,int start,int end){
    int pivotIndex=0;
    if (start<end){
        pivotIndex=partition(nums,start,end);
        quickSort(nums, start, pivotIndex);
        quickSort(nums, pivotIndex+1, end);
    }
}
void quickSort(vector<int>&nums){
    const int len=nums.size();
    quickSort(nums, 0, len);
}

//随机化快速排序
//快速排序面对特定的序列，比如升序或者逆序的排列，表现很不好。因为在选择主元时候，确定了选择左边第一个。
//针对这种情况，我们有了随机化选择主元的快速排序
//分区函数，对nums[start……end-1]分区，随机选择一个元素为主元，最后返回主元的下标
int randomizedPartition(vector<int>&nums,int start,int end){
    static default_random_engine e;//生成无符号随机数引擎
    uniform_int_distribution<unsigned> u(start,end-1);//均匀分布类型
    int piovtIndex=u(e);//生成随机主元下标
    //randomly select pivot, swap with first element
    //这样也可以！！
    //如果不这样做，直接按着主元随机位置，来进行Partition，不容易写
    int piovt=nums[piovtIndex];
    swap(nums[piovtIndex],nums[start]);
    piovtIndex=start;
    int storeIndex=piovtIndex+1;
    for(int i=piovtIndex+1;i<end;++i){
        //if(storeIndex==piovtIndex)++storeIndex;
        if(nums[i]<piovt){
            swap(nums[i],nums[storeIndex]);
            ++storeIndex;
        }
    }
    swap(nums[storeIndex-1],nums[piovtIndex]);
    return storeIndex-1;
}
void randomizedQuickSort(vector<int>&nums,int start,int end){
    if(start<end){
        int pivotIndex=randomizedPartition(nums, start, end);
        randomizedQuickSort(nums, start, pivotIndex);
        randomizedQuickSort(nums, pivotIndex+1, end);
    }
}
void randomizedQuickSort(vector<int>&nums){
    const int len=nums.size();
    randomizedQuickSort(nums, 0, len);
}
#endif