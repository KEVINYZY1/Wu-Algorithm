#include<vector>
using namespace std;

class Solution1 {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        makePermutations(nums, 0, nums.size()-1);
        return rec;
    }
    
private:
    vector<vector<int> > rec;
    void makePermutations(vector<int> nums, int low, int high) {
        if (low == high) {
            rec.push_back(nums);
            return;
        }
        for (int i= low; i <= high; i++) {
            int k;
            for(k=low;k<i;k++)if(nums[k]==nums[i])break; 
            if(k<i)continue;
            swap(nums[low], nums[i]);
            makePermutations(nums, low+1, high);
            swap(nums[low], nums[i]);
            /*
            if (low != k && nums[low] == nums[k]) continue;
            swap(nums[low], nums[k]);
            makePermutations(nums, low+1, high);
            //swap(nums[low], nums[k]);假如这样回溯回去，会出现很多重复的排列。
            */
        }
    }
};

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > allPer;
        if (num.empty()) 
            return allPer;
        sort(num.begin(), num.end());
        vector<int> per;
        vector<bool> used(num.size(), false);
        findPerUniq(num, used, per, allPer);
        return allPer;
    }
    
    void findPerUniq(vector<int> &num, vector<bool> &used, vector<int> &per, vector<vector<int> > &allPer) {
        if (per.size() == num.size()) {
            allPer.push_back(per);
            return;
        }
        
        for (int i = 0; i < num.size(); i++) {
            if (used[i]) 
                continue;
            if (i > 0 && num[i] == num[i-1] && !used[i - 1])//逆向思维
                continue;
            used[i] = true;
            per.push_back(num[i]);
            findPerUniq(num, used, per, allPer);
            per.pop_back();
            used[i] = false;
        }
    }
};