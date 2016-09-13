#include<vector>
using namespace std;

//去掉值为val的元素
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int newEnd=nums.size()-1;
        int end=nums.size()-1;
        for(;end>=0;end--){
            if(nums[end]==val){
                swap(nums[end],nums[newEnd]);
                newEnd--;
            }
        }
        return newEnd+1;
    }
};