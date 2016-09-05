#include<vector>
#include<complex>
using namespace std;

//在3sum的基础上做一些改动
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest=0,absolute=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i-1]==nums[i])
                continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>target){
                    k--;
                }
                else if(sum<target){
                    j++;
                }
                else return target;
                int temp=abs(sum-target);
                if(temp<absolute){
                    closest=sum;
                    absolute=temp;
                }
            }
        }
        return closest;
    }
};