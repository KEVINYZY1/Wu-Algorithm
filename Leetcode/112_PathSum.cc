#include<cstdlib>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//dfs
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return isPathsum(root,sum,0);
    }
private:
    bool isPathsum(TreeNode* root, int sum, int cursum){
        if(!root)
            return false;
        cursum+=root->val;
        if(root->left==NULL && root->right==NULL && cursum==sum)
            return true;
        return isPathsum(root->left,sum,cursum) || isPathsum(root->right,sum,cursum);
    }
};