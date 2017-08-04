#include<cstdlib>
#include<unordered_map>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = NULL;
        if (postorder.empty())
            return root;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        root = helpBuild(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }
private:
    unordered_map<int, int> m;//存放中序遍历的关系
    TreeNode* helpBuild(vector<int>& postorder, int s0, int e0, vector<int>& inorder, int s1, int e1) {
        if (s0 > e0 || s1 > e1) {
            return NULL;
        }
        int mid = m[postorder[e0]];//利用之前存放的中序遍历关系，瞬间确定根节点位置

        TreeNode* root = new TreeNode(postorder[e0]);

        int num = mid - s1;

        root->left = helpBuild(postorder, s0, s0 + num - 1, inorder, s1, mid - 1);//左子树
        root->right = helpBuild(postorder, s0 + num, e0 - 1, inorder, mid + 1, e1);//右子树

        return root;
    }
};