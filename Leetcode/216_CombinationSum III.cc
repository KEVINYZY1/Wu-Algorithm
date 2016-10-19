#include<vector>
using namespace std;

//1-9,只能用一次，并且每个组合里面没有重复元素
class Solution {
public:
    Solution():candidates({1,2,3,4,5,6,7,8,9}){}//构造函数
    vector<vector<int>> combinationSum3(int k, int n) {
        int depth=k;
        vector<int>temp;
        for(int i=0;i<9;++i){
            if(candidates[i]>n)break;
            findCandidates(temp,i,n,depth);
        }
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int>candidates;
    void findCandidates(vector<int>temp,int i,int minuend,int depth){
        if(--depth<0)
            return;
        temp.push_back(candidates[i]);
        minuend-=candidates[i];
        if(minuend>0){
            for(int j=1;j<9-i;++j){
                if(minuend-candidates[i+j]<0)return;
                else findCandidates(temp,i+j,minuend,depth);
            }
        }
        else if(minuend<0){
            return;
        }
        else if(minuend==0){
            if(depth==0)
            result.push_back(temp);
        }
    }
};