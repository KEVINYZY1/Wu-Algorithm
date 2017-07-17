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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
        if (root == NULL)
            return result;
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {
            auto temp = q1.front();
            q1.pop();
            result.push_back(temp->val);
            if (temp->left)
                q1.push(temp->left);
            if (temp->right)
                q1.push(temp->right);
        }
        return result;
    }
};