#include<cstdlib>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == NULL)
            return NULL;
        stack<TreeNode*> node;
        int count = 0;
        while (pRoot != NULL || !node.empty()) {
            while(pRoot != NULL) {
                node.push(pRoot);
                pRoot = pRoot->left;
                
            }
            if (!node.empty()) {
                pRoot = node.top();
                node.pop();
                count++;
                if (count == k)
                    return pRoot;
                pRoot = pRoot->right;
            }
        }
        return NULL;
    }
};