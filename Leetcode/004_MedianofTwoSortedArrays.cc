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



//方法2，用两个指针从两个数组开头开始遍历，比较大小，指向小的那个的指针++，然后k--，直到k为0，找到要找的元素。
//可以根据k的大小，来判断从数组头遍历，还是数组尾遍历
//缺陷，不过时间复杂度为O(n)，虽然优于方法1，但还不是不够好 


//假如再将问题扩展一下，找的是两组数组中第k个元素，而不是中位数呢
//方法3，如果A[k/2-1]<B[k/2-1]，那么A[0]~A[k/2-1]一定在第k小的数的序列当中
//递归方法更好理解，然而迭代效率更高，这次时间复杂度终于到O(lg(m+n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1=nums1.size();
        int N2=nums2.size();
        if (N1<N2) {
            nums1.swap(nums2);//保证数组num1是最长的
            swap(N1,N2);
        }
        int k=(N1+N2-1)/2;//第k个元素，另外k必然比N2大
        int low=0,high=(k>N2)?N2:k;
        while(low<high){
            int m2=(low+high)/2;
            int m1=k-m2;
            if(nums1[m1]<nums2[m2]){
                high=m2;
            }
            else{
                low=m2+1;
            }
        }
        int left=max(low>0? nums2[low-1]:INT_MIN, k-low<N1? nums1[k-low]:INT_MIN);
        if((N1+N2)&1) return left;
        int right=min(low<N2? nums2[low]:INT_MAX, k-low+1<N1? nums1[k-low+1]:INT_MAX);
        double result=(double)(left+right)/2;
        /*这里必须加类型转换
        *补充一下，double a=1/3  a的结果为0.0 
        */
        return result;
    }
};