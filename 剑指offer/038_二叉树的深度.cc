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

class Solution {
public:
    int TreeDepth(TreeNode* pRoot){
    	if (pRoot == NULL)
            return 0;
        int leftDepth = TreeDepth(pRoot->left);
        int rightDepth = TreeDepth(pRoot->right);
        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
    }
};