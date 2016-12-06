#include<cstdlib>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
  
//由前序和中序遍历，反推二叉搜索树
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=NULL;
        if(preorder.empty())
            return root;
        for(int i=0; i<inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        root=helpBuild(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }
private:
    unordered_map<int, int> m;//存放中序遍历的关系
    //s0,e0,s1,e1分别代表了前序和中序的范围
    TreeNode* helpBuild(vector<int>& preorder, int s0, int e0, vector<int>& inorder, int s1, int e1){
        if(s0>e0 || s1>e1) {
            return NULL;
        }
        int mid = m[preorder[s0]];//利用之前存放的中序遍历关系，瞬间确定根节点位置

        TreeNode* root = new TreeNode(preorder[s0]);

        int num = mid-s1;

        root->left = helpBuild(preorder, s0+1, s0+num, inorder, s1, mid-1);//左子树
        root->right = helpBuild(preorder, s0+num+1, e0, inorder, mid+1, e1);//右子树

        return root;
    }
};