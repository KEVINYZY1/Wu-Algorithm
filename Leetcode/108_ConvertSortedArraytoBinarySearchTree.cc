#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//将排好序的数组转换为平衡搜索树
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        return buildBST(nums, 0, nums.size());
    }
private:
    TreeNode* buildBST(vector<int>& nums, int start, int end){//左闭右开
        if(start>=end)
            return NULL;
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=buildBST(nums, start, mid);
        root->right=buildBST(nums, mid+1, end);
        return root;
    }
};