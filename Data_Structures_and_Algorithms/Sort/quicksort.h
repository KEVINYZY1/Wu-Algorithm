#ifndef _QUICKSORT_H
#define _QUICKSORT_H
#include <vector>
#include<utility>
#include<random>
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

//按算法导论第7章的思考题第二题
//针对输入数组中存在重复元素的情况，对快速排序进行优化pair
//分区函数，对nums[start……end-1]分区，选择第一个元素为主元，最后返回一个主元的范围下标q和t
pair<int,int> repeatElementPartition(vector<int>&nums,int start,int end){
    static default_random_engine e;//生成无符号随机数引擎
    uniform_int_distribution<unsigned> u(start,end-1);//均匀分布类型
    int piovtIndex=u(e);
    int piovt=nums[piovtIndex];
    swap(nums[piovtIndex],nums[start]);
    int q,t;
    start++;
    q=start;
    //先遍历一遍数组，把小于主元的全部放在[start+1,q-1]
    for(int i=start;i<end-1;i++){
        if(nums[i]<piovt){
            swap(nums[i],nums[q]);
            q++;
        }
    }
    for(int i=q+1;i<end-1&&nums[i]==piovt;i++){
        t=i;
    }
    t++;
    for(int i=t+1;i<end-1;i++){
        if(nums[i]==piovt){
            swap(nums[i],nums[t]);
            t++;
        }
    }
    return make_pair(q,t);
}
void repeatElementQuickSort(vector<int>&nums,int start,int end){
    if(start<end){
        pair<int,int>s=repeatElementPartition(nums,start,end);
        repeatElementQuickSort(nums,start,s.first+1);
        repeatElementQuickSort(nums,s.second,end);
    }
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



//fuzzysort，针对数组都处于一个模糊区间的排序。算法导论第七章思考题最后一题
//假定输入元素的区间用pair<int,int>来表示
//有点类似于针对重复元素的快速排序，把区间重合的元素当做相等元素来处理
class fuzzySort{
    private:
        bool intersects(pair<int,int> a, pair<int,int> b) { return a.first <= b.second && b.first <= a.second; }
        bool before(pair<int,int> a, pair<int,int> b)     { return a.second < b.first; }
        bool after(pair<int,int> a, pair<int,int> b)      { return a.first > b.second; }
        pair<int,int> fuzzySortPartition(vector<pair<int,int> >&nums,int start,int end){
            pair<int,int>piovt=nums[start];
            start++;
            int s=start,t;
            //确定一个区间元素集合和主元piovt所有区间元素的公共区间（交集）
            for (int i = s; i < end; i++) {
                if (intersects(piovt, nums[i])) {
                    if (nums[i].first > piovt.first)
                        piovt.first = nums[i].first;
                    if (nums[i].second < piovt.second)
                        piovt.second = nums[i].second;
                }
            }
            for (int i = s; i < end; i++) {
                if (before(nums[i], piovt)) {
                    swap(nums[i], nums[s]);
                    s++;
                }
            }
            for (int i = s; i < end; i++) {
                if (before(nums[i], piovt)) {
                    swap(nums[i], nums[s]);
                    s++;
                }
            }
            swap(nums[end-1],nums[s]);
            for (int t = s+1, i=end-1; t <= i; ) {
                if (intersects(nums[i], piovt)) {
                    swap(nums[i], nums[t]);
                    t++;
                }
                else i--;
            }
            return make_pair(s,t);
        }
    public:
        void letsFuzzySort(vector<pair<int,int> >&nums,int start,int end){
            if(start<end){
                pair<int,int>temp=fuzzySortPartition(nums,start,end);
                letsFuzzySort(nums,start,temp.first);
                letsFuzzySort(nums,temp.second,end);
            }
        }
};


#endif