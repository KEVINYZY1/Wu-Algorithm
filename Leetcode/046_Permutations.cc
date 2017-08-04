#include<vector>
using namespace std;

//回溯法
class Solution1 {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        int len = nums.size();
        makePermutations(0, len - 1, nums);
        return rec;
    }
private:
    void makePermutations(int low, int high, vector<int>& nums) {
        if (low == high) {
            rec.push_back(nums);
        } else {
            for (int i = low; i <= high; i++) {
                swap(nums[i], nums[low]);
                makePermutations(low + 1, high, nums);
                swap(nums[i], nums[low]);//必须要有这步，一个分支走完了，再返回，继续走
            }
        }
    }
    vector<vector<int> >rec;
};


//更容易理解
class Solution2 {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > allPer;
        if (num.empty()) 
            return allPer;
        vector<bool> used(num.size(), false);
        vector<int> per;
        findPermutations(num, used, per, allPer);
        return allPer;
    }
private:
    void findPermutations(vector<int> &num, vector<bool> &used, vector<int> &per, vector<vector<int> > &allPer) {
        if (per.size() == num.size()) {
            allPer.push_back(per);
            return;
        }
        
        for (int i = 0; i < num.size(); i++) {
            if (used[i]) 
                continue;
            used[i] = true;
            per.push_back(num[i]);
            findPermutations(num, used, per, allPer);
            used[i] = false;
            per.pop_back();
        }
    }
};