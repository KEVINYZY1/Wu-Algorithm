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

//请实现一个函数，用来判断一颗二叉树是不是对称的。
//注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot){
    	if(pRoot==NULL)
            return true;
        return helper(pRoot->left,pRoot->right);
    }
private:
    bool helper(TreeNode* l,TreeNode*r){
        if(l==NULL&&r==NULL)
            return true;
        if(l==NULL||r==NULL)
            return false;
        if(l->val!=r->val)
            return false;
        return helper(l->left,r->right)&&helper(l->right,r->left);
    }

};