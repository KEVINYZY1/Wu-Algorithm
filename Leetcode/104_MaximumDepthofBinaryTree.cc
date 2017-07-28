#include<cstdlib>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
//求二叉树最大深度，dfs,就是在正常找树的高
    int maxDepth(TreeNode* root) {
        return getMaxDepth(root);
    }
private:
    int getMaxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int ld = getMaxDepth(root->left);
        int rd = getMaxDepth(root->right);
        return ld > rd ? (ld + 1) : (rd + 1);
    }
};