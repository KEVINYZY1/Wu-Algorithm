#include<vector>
using namespace std;
//方法1 归并排序中的合并步骤  时间复杂度并不符合要求
class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result=0;
        if(nums1.empty()&&nums2.empty())
            return result;
        vector<int>nums;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                nums.push_back(nums1[i]);
                ++i;
            }
            else{
                nums.push_back(nums2[j]);
                ++j;
            }
        }
        if(i<nums1.size()){
            while(i<nums1.size()){
                nums.push_back(nums1[i++]);
            }
        }
        if(j<nums2.size()){
            while(j<nums2.size()){
                nums.push_back(nums2[j++]);
            }
        }
        int mid=nums.size()/2;
        if((nums.size()%2)==1){
            result=nums[mid];
        }
        else{
            result=nums[mid]+nums[mid-1];
            result/=2;
        }
        return result;
    }
};

//假如再将问题扩展一下，找的是两组数组中第k个元素，而不是中位数呢