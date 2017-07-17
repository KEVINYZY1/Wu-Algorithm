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

//输入两棵二叉树A，B，判断B是不是A的子结构。
//（ps：我们约定空树不是任意一个树的子结构）

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == NULL || pRoot2 == NULL)
            return false; 
		if (pRoot1->val == pRoot2->val) {
            if(isSameTree(pRoot1, pRoot2))
                return true;
        }
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
private:
    bool isSameTree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == NULL)
            return true;
        if (pRoot1 == NULL)//别忘
            return false;
		if (pRoot1->val != pRoot2->val)
            return false;
        return isSameTree(pRoot1->left, pRoot2->left) && isSameTree(pRoot1->right, pRoot2->right);
    }
};