#include<vector>
using namespace std;

//关键是不使用额外的数组
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            swap(nums1,nums2);
            return;
        }
        if(n==0)
            return;
        int i=m-1,j=n-1;
        int index=m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>nums2[j]){
                nums1[index]=nums1[i];
                i--;
                index--;
            }else{
                nums1[index]=nums2[j];
                j--;
                index--;
            }
        }
        while(i>=0){
            nums1[index]=nums1[i];
            i--;
            index--;
        }
        while(j>=0){
            nums1[index]=nums2[j];
            j--;
            index--;
        }
    }
};