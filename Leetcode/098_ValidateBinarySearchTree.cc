#include<cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*错误解法，不是说根节点的左右子树值大小符合就可以了，还有整体也要符合。[2,1,3,0,4]通过不了
bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left){
            if(root->left->val>=root->val)
                return false;
        }
        if(root->right){
            if(root->right->val<root->val)
                return false;
        }
        return isValidBST(root->right) && isValidBST(root->left);
    }
*/

 //如何判断是否为一个二叉搜索树
 //而且是一个严格増序，没有相同元素的二叉树

//过不了INT_MAX和INT_MIN的测试用例- -
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return validateBST(root, INT_MIN, INT_MAX);
    }
    
    bool validateBST(TreeNode *root, int minVal, int maxVal) {
        if(!root) return true;
        if(root->val<=minVal || root->val>=maxVal) return false;
        return validateBST(root->left, minVal, root->val) && validateBST(root->right, root->val, maxVal);
    }
};


//下面两个思路都是一样的，中序遍历，只记录前一个的值，记录方式不一样，决定了能不能通过INT_MAX之类的测试用例
//这个可以通过
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) 
            return true;
        if (!validate(node->left, prev)) 
            return false;
        if (prev != NULL && prev->val >= node->val) 
            return false;
        prev = node;
        return validate(node->right, prev);
    }
};
//这个过不了
class Solution3 {
public:
    bool isValidBST(TreeNode *root) {
        int curMax = INT_MIN;
        return validateBST(root, curMax);
    }
    
    bool validateBST(TreeNode *root, int &curMax) {
        if(!root) return true;
        if(!validateBST(root->left, curMax)) return false;
        if(curMax >= root->val) return false;
        curMax = root->val;
        return validateBST(root->right, curMax);
    }
};