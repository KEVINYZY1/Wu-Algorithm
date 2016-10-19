#include<vector>
using namespace std;

//candidates数组中元素可以重复使用
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        const int len=candidates.size();
        vector<int>temp;int sum=0;
        for(int i=0;i<len;++i){
            if(candidates[i]>target)break;
            findCombination(temp,sum,candidates,i,result,target);
        }
        return result;
    }
private:
    void findCombination(vector<int>temp, int sum, const vector<int> &candidates, int i, vector<vector<int>> &result,int target){
        temp.push_back(candidates[i]);
        sum+=candidates[i];
        if(sum<target){
            for(int j=0;j<candidates.size()-i;++j){
                if(sum+candidates[i+j]>target)return;
                else{
                    findCombination(temp,sum,candidates,i+j,result,target);
                }
            }
        }
        else if(sum>target){
            return;
        }
        else if(sum==target){
            result.push_back(temp);
        }
    }
};