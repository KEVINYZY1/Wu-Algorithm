#include<vector>
using namespace std;

//unique实现,nums已经排好了序
//这题使用迭代器做指针的话，需要小心，因为对vector中元素修改，也会改变它的迭代器
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int i=0,x=0;
        while(x+1!=nums.size()){
            if(nums[x]!=nums[x+1]){
                nums[++i]=nums[x+1];
            }
            x++;
        }
        return i+1;
    }
};