#include<cstdlib>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        if (root == NULL)
            return result;
        findPathSum(result, root, sum, vector<int>());
        return result;
    }
private:
    void findPathSum(vector<vector<int> > &result, TreeNode* node, int sum, vector<int> temp) {
        if (!node)
            return;
        sum -= node->val;
        temp.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            if (sum == 0)
                result.push_back(temp);
        //不需要对sum判断进行剪枝，sum有可能为负的
        } else {
            findPathSum(result,node->left,sum,temp);
            findPathSum(result,node->right,sum,temp);
        }
    }
};