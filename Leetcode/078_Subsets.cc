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

//迭代
class Solution3 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> allSets;
        vector<int> sol;
        allSets.push_back(sol);
        sort(S.begin(), S.end());
        for(int i=0; i<S.size(); i++) {
            int n = allSets.size();
            for(int j=0; j<n; j++) {
                sol = allSets[j];
                sol.push_back(S[i]);
                allSets.push_back(sol);
            }
        }
        return allSets;
    }
};

//由于S[0: n-1]组成的每一个subset，可以看成是对是否包含S[i]的取舍。
//S[i]只有两种状态，包含在特定subset内，或不包含。所以subset的数量总共有2^n个。
//所以可以用0~2^n-1的二进制来表示一个subset。
//二进制中每个0/1表示该位置的S[i]是否包括在当前subset中。

class Solution4 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> allSets;
        sort(S.begin(), S.end());
        unsigned long long maxNum = pow(2, S.size()) - 1;
        for(unsigned long long i=0; i<=maxNum; i++) 
            allSets.push_back(num2subset(S, i));
        return allSets;
    }
    
    vector<int> num2subset(vector<int> &S, unsigned long long num) {
        vector<int> sol;
        int i=0;
        while(num) {
            if(num & 1) sol.push_back(S[i]);
            num >>= 1;
            i++;
        }
        return sol;
    }
};