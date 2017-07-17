#include<cstdlib>
#include<vector>
#include<map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		TreeNode* root = NULL;
        if (vin.empty() || pre.empty())
            return root;
        const int len = pre.size();
        map<int, int> m;
        for (int i = 0; i < len; i++) {
            m[vin[i]] = i;
        }
        return buildBinaryTree(root, pre, 0, len - 1, m, 0, len - 1);
    }
private:
    TreeNode* buildBinaryTree(TreeNode * root, vector<int>& pre, int s1, int e1,
                              map<int, int>& m, int s2, int e2) {
        if (s1 > e1)
            return NULL;
        root = new TreeNode(pre[s1]);
        int num = m[pre[s1]];
        int leftLength = num - s2;
        int rightLength = e2 - num;
        root->left = buildBinaryTree(root->left, pre, s1 + 1, s1 + leftLength, m, s2, s2 + leftLength - 1);
        root->right = buildBinaryTree(root->right, pre, s1 + leftLength + 1, e1, m, num + 1, e2);
        return root;
    }
};