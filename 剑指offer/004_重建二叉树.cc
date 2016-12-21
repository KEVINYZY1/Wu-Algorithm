#include<cstdlib>
#include<vector>
#include<map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if(pre.empty())
            return NULL;
        TreeNode* root=NULL;
        map<int,int> inorder;
        for(int i=0;i<vin.size();i++){
            inorder[vin[i]]=i;
        }
        return buildBinaryTree(root,pre,0,pre.size()-1,inorder,0,pre.size()-1);
        
    }
private:
    TreeNode* buildBinaryTree(TreeNode* root, vector<int> &pre,int s0,int e0,map<int,int> &inorder,int s1,int e1){
        if(s0>e0)
            return NULL;
        root=new TreeNode(pre[s0]);
        int m=inorder[pre[s0]];
        int leftTreeLength=m-s1;
        int rightTreeLength=e1-m;
        root->left=buildBinaryTree(root->left,pre,s0+1,s0+leftTreeLength,inorder,s1,s1+leftTreeLength-1);
        root->right=buildBinaryTree(root->right,pre,s0+1+leftTreeLength,e0,inorder,s1+leftTreeLength+1,e1);
        return root;
    }
};