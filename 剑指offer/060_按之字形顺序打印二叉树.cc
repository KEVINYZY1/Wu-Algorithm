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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        if (pRoot == NULL)
            return result;
        queue<TreeNode*> q1;
        q1.push(pRoot);
        int rows = 1;
        while (!q1.empty()) {
            queue<TreeNode*> q2;
            vector<int> temp;
            while (!q1.empty()) {
            	auto node = q1.front();
            	q1.pop();
                temp.push_back(node->val);
            	if (node->left)
                	q2.push(node->left);
            	if (node->right)
                	q2.push(node->right);
            }
            if((rows & 1) == 0)
                reverse(temp.begin(), temp.end());
            rows++;
            result.push_back(temp);
            q1.swap(q2);
        }
        return result;
    }
    
};