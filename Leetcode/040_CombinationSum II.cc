#include<vector>
using namespace std;

//candidates数组中元素只能使用一次
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        nums=candidates;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        const int len=nums.size();
        for(int i=0;i<len;++i){
            if(nums[i]>target)break;
            if(nums[i]==nums[i-1]&&i>0)continue;//蛮重要的
            findCandidates(temp,target,i);
        }
        return result;
    }
private:
    vector<vector<int>>result;
    vector<int> nums;
    void findCandidates(vector<int>temp,int minuend,int i){
        temp.push_back(nums[i]);
        minuend-=nums[i];
        const int len=nums.size();
        if(minuend>0){
            for(int j=1;j<len-i;++j){
                if(minuend-nums[i+j]<0)return;
                else findCandidates(temp,minuend,i+j);
            }
        }
        else if(minuend<0){
            return;
        }
        else if(minuend==0){
            if(find(result.begin(),result.end(),temp)==result.end())
                result.push_back(temp);
        }
    }
};