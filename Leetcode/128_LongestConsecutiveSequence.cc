#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

//找出一个整数数组中，最大的连续数字排列的长度
//要求O(n)时间，不然直接排序就可以了。
//方法1，哈希表，空间换取时间，注意已经被发现的子序列，从哈希表中移除。
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int maxLength=0;
        const int len=nums.size();
        for(int i=0; i<len; i++){
            hash_.insert(nums[i]);
        }
        for(int i=0; i<len; i++){
            if(hash_.find(nums[i])!=hash_.end()){
                int ascend=findNum(ASCEND,nums[i]);
                int decend=findNum(DECEND,nums[i]);
                hash_.erase(nums[i]);
                maxLength=max(maxLength,ascend+decend-1);
            }
        }
        return maxLength;
    }
private:
    std::unordered_set<int> hash_;
    enum OrderBy{ASCEND,DECEND};
    int findNum(OrderBy od, int value){
        int maxLen = 0;
        int a=value;
        while(hash_.find(a)!=hash_.end()){
            maxLen++;
            if(a!=value)
                hash_.erase(a);
            if(od==ASCEND)
                a++;
            else a--;
            
        }
        return maxLen;
    }
};