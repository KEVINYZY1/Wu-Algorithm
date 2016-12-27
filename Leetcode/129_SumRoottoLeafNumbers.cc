#include<cstdlib>
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
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        return calSum(root,0);
    }
private:
    int calSum(TreeNode* root, int count){
        count*=10;
        count+=root->val;
        if(root->left==NULL && root->right==NULL)
            return count;
        
        int left=0;
        int right=0;
        if(root->left)
            left=calSum(root->left,count);
        if(root->right)
            right=calSum(root->right,count);
        return right+left;
    }
};