#include<vector>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty())
            return false;
        const int len = nums.size();
        if(len == 1)//边界条件
            return false;
        map<int,set<int>>m;//second存放的是索引集合
        for(size_t i=0;i<len;++i){
            m[nums[i]].insert(i);
        }
        for(size_t i=0; i<len; ++i){
           if(m[nums[i]].size() >= 2){
                for(set<int>::iterator it = m[nums[i]].begin(); it != --m[nums[i]].end(); ++it){
                    auto cur=it;
                    if((*++cur-*it)<=k)
                        return true;
                }
           }
        }
        return false;   
    }
};
