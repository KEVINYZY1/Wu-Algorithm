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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        recursionPreorderTraversal(result,root);
        return result;
    }
    void recursionPreorderTraversal(vector<int>&result,TreeNode* root){
        if(!root)
            return;
        result.push_back(root->val);
        if(root->left)
            recursionPreorderTraversal(result,root->left);
        if(root->right)
            recursionPreorderTraversal(result,root->right);
    }
};


//方法2，迭代版，更有难度，用了一个栈作为辅助数据结构
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        stack<TreeNode*>storeTreeNode;
        storeTreeNode.push(root);
        TreeNode* lastRoot=NULL;
        while(!storeTreeNode.empty()){
            //这里要记录root的是否变化，不然的话，会重复记录节点的值。
            if(lastRoot!=root){
                result.push_back(root->val);
                lastRoot=root;
            }
            if(root->left){
                storeTreeNode.push(root->left);
                root=root->left;
            }
            else{
                auto node=storeTreeNode.top();
                storeTreeNode.pop();
                if(node->right){
                    storeTreeNode.push(node->right);
                    root=node->right;
                }
            }
        }
        return result;
    }
};