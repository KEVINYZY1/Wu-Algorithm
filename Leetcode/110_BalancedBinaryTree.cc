#include<cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//判断二叉树是不是一个平衡二叉树
//二叉平衡树不仅要求每个节点的左右子树深度差不大于1；同时要求它的左右子节点也满足同样的条件
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int lD=getDepth(root->left);
        int rD=getDepth(root->right);
        int def=lD-rD;
        if(def<-1||def>1)
            return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
private:
//获取二叉树的深度
    int getDepth(TreeNode* t){
        if(t==NULL)
            return 0;
        int leftDepth=getDepth(t->left);
        int rightDepth=getDepth(t->right);
        return (leftDepth>rightDepth)?(leftDepth+1):(rightDepth+1);
    }
};