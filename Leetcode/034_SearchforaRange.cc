#include<vector>
using namespace std;


//方法1，二分法找到target，然后再向两边扩展。
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int len=nums.size();
        if(len==0)
            return {-1,-1};
        binarySearch(0,len-1,nums,target);
        return pos;
    }
    void binarySearch(int low,int high,vector<int>& nums,int target){
        int mid=low+(high-low)/2;
        const int len=nums.size();
        if(nums[mid]>target){
            if(high==low){
            pos={-1,-1};
            return;
        }
            binarySearch(low,mid,nums,target);
            return;
        }
        else if (nums[mid]<target){
            if(high==low){
                pos={-1,-1};
                return;
            }
            binarySearch(mid+1,high,nums,target);//关键
            return;
        }
        else if (nums[mid]==target){
            int minpos=mid;int maxpos=mid;
            while(mid>0&&nums[--mid]==target)minpos=min(minpos,mid);
            while(mid<len-1&&nums[++mid]==target)maxpos=max(maxpos,mid);
            pos={minpos,maxpos};
            return;
        }
    }
private:
    vector<int>pos;
};


//方法2，使用stl算法，分别查找target范围的左右边界
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto itup = upper_bound(nums.begin(), nums.end(), target);
		auto itlow = lower_bound(nums.begin(), nums.end(), target);
		vector<int> res;
		if (*itlow == target)
			res.push_back(itlow-nums.begin());
		else res.push_back(-1);
		if (*(itup-1) == target)
			res.push_back(itup-nums.begin()-1);
		else res.push_back(-1);
		return res;
    }
};