#include<cstdlib>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


//方法1，递归版
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        recursionInorderTraversal(result,root);
        return result;
    }
    void recursionInorderTraversal(vector<int>&result,TreeNode* root){
        if(!root)
            return;
        if(root->left)
            recursionInorderTraversal(result,root->left);
        result.push_back(root->val);
        if(root->right)
            recursionInorderTraversal(result,root->right);
    }
};

//方法2，迭代版，更有难度，用了一个栈作为辅助数据结构
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        stack<TreeNode*>storeTreeNode;
        storeTreeNode.push(root);
        while(!storeTreeNode.empty()){
            if(root->left){
                storeTreeNode.push(root->left);
                root=root->left;
            }
            else{
                auto node=storeTreeNode.top();
                storeTreeNode.pop();
                result.push_back(node->val);
                if(node->right){
                    storeTreeNode.push(node->right);
                    root=node->right;
                }
            }
        }
        return result;
    }
};