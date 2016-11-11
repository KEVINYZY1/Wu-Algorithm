#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int depth=k;
        size=n;
        vector<int>temp;
        for(int i=0;i<n;++i){
            findCombination(temp,i,depth);
        }
        return result;
    }
private:
    vector<vector<int>>result;
    int size;
    void findCombination(vector<int>temp,int i,int depth){
        temp.push_back(i+1);
        --depth;
        if(depth>0){
            for(int j=1;j<size-i;++j){
                findCombination(temp,i+j,depth);
            }
        }
        else if(depth==0){
            result.push_back(temp);
        }
    }
};