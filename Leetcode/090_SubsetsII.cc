#include<vector>
using namespace std;

//带有重复元素的集合
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> allSets;
        vector<int> sol;
        allSets.push_back(sol);
        sort(S.begin(), S.end());
        findSubsetsWithDup(S, 0, sol, allSets);
        return allSets;
    }
    
    void findSubsetsWithDup(vector<int> &S, int start, vector<int> &sol, vector<vector<int>> &allSets) {
        for(int i=start; i<S.size(); i++) {
            if(i>start && S[i]==S[i-1]) continue;
            sol.push_back(S[i]);
            allSets.push_back(sol);
            findSubsetsWithDup(S, i+1, sol, allSets);//这里是i+1，而不是start+1
            sol.pop_back();
        }
    }
};