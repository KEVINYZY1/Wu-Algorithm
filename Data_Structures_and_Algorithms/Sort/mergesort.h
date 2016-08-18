#ifndef _MERGESORT_H
#define _MERGESORT_H
#include <vector>
using namespace std;
//归并排序
//合并2个有序数组 nums[start……mid]和nums[mid+1……end]
void combineArray(vector<int>&nums,int start,int mid,int end){
    vector<int>temp(end+1-start,0);
    int i=start,m=mid;
    int j=mid+1,n=end;
    int k=0;
    while(i<=m&&j<=n){
        if(nums[i]>nums[j]){
            temp[k++]=nums[j++];
        }
        else if(nums[i]<=nums[j]){
            temp[k++]=nums[i++];
        }
    }
    while(i<=m){
        temp[k++]=nums[i++];
    }
    while(j<=n){
        temp[k++]=nums[j++];
    }
    for(int d=0;d<k;++d){//k最后还++了一次，所以没有等于号
        nums[start+d]=temp[d];
    }
}
void mergeSort(vector<int>&nums,int start,int end){
    int mid=start+(end-start)/2;
    if(start<end){
        mergeSort(nums, start, mid);
        mergeSort(nums,mid+1,end);
        combineArray(nums, start, mid, end);
    }
    
}
void mergeSort(vector<int>&nums){
    const int len=nums.size();
    mergeSort(nums,0,len-1);
}
#endif