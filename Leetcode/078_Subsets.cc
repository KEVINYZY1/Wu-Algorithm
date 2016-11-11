#include<vector>
using namespace std;

//给定一个无重复的集合，要求给出所有子集合的可能
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        findSubSet(vector<int>(),nums);
        return result;
    }
private:
    vector<vector<int>> result;
    void findSubSet(vector<int>subSet, vector<int>& nums){
        result.push_back(subSet);
        int start=0;
        if(subSet.empty())
            start=0;
        else{
            int target=subSet[subSet.size()-1];
            start=binarySearch(nums,target)+1;
        }
        for(;start<nums.size();start++){
            auto temp=subSet;
            temp.push_back(nums[start]);
            findSubSet(temp,nums);
        }
    }
    int binarySearch(vector<int>& nums,int target){
        int low=0;
        int high=nums.size()-1;
        int mid;
        while(low<=high){//等号
            mid=low+(high-low)/2;
            if(nums[mid]>target)
                high=mid-1;
            else if(nums[mid]<target)
                low=mid+1;
            else return mid;
        }
        return -1;//这题不会出现
    }
};

class Solution2 {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > results;
        vector<int> subset;
        helper(results, subset, nums, 0);
        return results;
    }
private:
    void helper(vector<vector<int> > &results, vector<int> &subset, vector<int> &nums, int start) {
        results.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            helper(results, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};