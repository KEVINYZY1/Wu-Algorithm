#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}    
};

//完全二叉树，找最右边的叶子节点
int findNumTree(TreeNode* root) {
    int res = 0;
    if (root == NULL) {
        return res;
    }

}
//l表示node所在树的层数，
int helper(TreeNode* node, int l, int h) {

}
//找node节点最左边的节点
int mostLeftLevel(TreeNode* node, int level) {
    while (node) {
        level++;
        node = node->left;
    }
    return level - 1;
}

int main () {
    TreeNode
}