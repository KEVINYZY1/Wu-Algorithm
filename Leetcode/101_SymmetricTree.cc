#include<cstdlib>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//方法1，迭代，检查一下每一层，层次遍历
class Solution1 {
public:
    bool isSymmetric(TreeNode *root){  
        if(root==NULL)
            return true;  
        queue<TreeNode*> lt,rt;  
        if(root->left) lt.push(root->left);  
        if(root->right) rt.push(root->right);  
        TreeNode* l;  
        TreeNode* r;  
        while(!lt.empty() && !rt.empty()){  
            l = lt.front();lt.pop();  
            r = rt.front();rt.pop();  
            if(l == NULL && r == NULL) 
                continue;  
            if(l == NULL || r == NULL) 
                return false;  
            if(l->val != r->val) 
                return false;  
            lt.push(l->left);  
            lt.push(l->right);  
            rt.push(r->right);  
            rt.push(r->left);  
        }  
        if(lt.empty() && rt.empty())  
            return true;  
        else  
            return false;  
    } 
};

//方法2，递归
/*
其中左子树和右子树对称的条件：
1 两个节点值相等，或者都为空
2 左节点的左子树和右节点的右子树对称
3 左节点的右子树和右节点的左子树对称
*/
class Solution2 {
public:
    bool isSymmetric(TreeNode *root) {  
        if (root == NULL)
            return true;
        return helpSymmetric(root->left, root->right);
    }
private:
    bool helpSymmetric(TreeNode *l, TreeNode *r) {
        if (l == NULL && r == NULL)
            return true;
        if (l == NULL)
            return false;
        if (r == NULL)
            return false;
        if (l->val != r->val)
            return false;
        return helpSymmetric(l->left, r->right) && helpSymmetric(l->right, r->left);
    }
};