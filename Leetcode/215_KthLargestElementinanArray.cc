#include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int len=nums.size();
        assert(k<=len);
        int low=0, high=len-1;
        while(low<=high){
            int index=partition(nums,low,high);
            int tempK=high-index+1;
            if(k>tempK){
                k-=tempK;
                high=index-1;
            }
            else if(k<tempK){
                low=index+1;
            }
            else return nums[index];
        }
        return -1;
    }
private:
    int partition(vector<int>& nums, int start, int end){
        int pivotIndex=start;
        int pivot=nums[pivotIndex];
        int storeIndex=pivotIndex+1;
        for (int i=pivotIndex+1; i<=end; ++i) {
            if(nums[i]<pivot){
                swap(nums[i],nums[storeIndex]);
                ++storeIndex;
            }
        }
        swap(nums[pivotIndex],nums[storeIndex-1]);//这里storeIndex要减1
        return storeIndex-1;
    }
};