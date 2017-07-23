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
    bool IsBalanced_Solution(TreeNode* pRoot) {
		int height = 0;
        return IsBalanced(pRoot, height);
    }
    bool IsBalanced(TreeNode* pRoot, int &height){
        if (pRoot == NULL)
            return true;
        int leftHeight = 0;
        if (pRoot->left) {
            if (!IsBalanced(pRoot->left, leftHeight))
                return false;
        }
        int rightHeight = 0;
        if (pRoot->right) {
            if (!IsBalanced(pRoot->right, rightHeight))
                return false;
        }
        height = max(rightHeight, leftHeight) + 1;
        if (abs(rightHeight - leftHeight) > 1)
            return false;
        return true;
    }
};