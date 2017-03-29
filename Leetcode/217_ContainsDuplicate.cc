#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> hash;
        for(auto a: nums){
            if(hash.find(a)!=hash.end())
                return true;
            hash.insert(a);
        }
        return false;
    }
};