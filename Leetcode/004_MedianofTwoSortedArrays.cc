#include<vector>
using namespace std;
class Solution {
public:
//归并排序
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