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

//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int> > result;
        if (root == NULL)
            return result;
        findWays(result, expectNumber, vector<int>(), root);
        return result;
    }
private:
    void findWays(vector<vector<int> >& result, int expectNumber, vector<int>temp, TreeNode* root){
        if (expectNumber < 0)
            return;
        if (root == NULL)
            return;
        
        expectNumber -= root->val;
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
            if (expectNumber == 0) {
            	result.push_back(temp);
            	return;
        	}
        findWays(result, expectNumber, temp, root->left);
        findWays(result, expectNumber, temp, root->right);
    }
};