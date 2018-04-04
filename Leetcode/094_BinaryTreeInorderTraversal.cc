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


//方法1，递归版
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        recursionInorderTraversal(result,root);
        return result;
    }
    void recursionInorderTraversal(vector<int>&result, TreeNode* root) {
        if (!root)
            return;
        if (root->left)
            recursionInorderTraversal(result, root->left);
        result.push_back(root->val);
        if (root->right)
            recursionInorderTraversal(result, root->right);
    }
};

//方法2，迭代版，更有难度，用了一个栈作为辅助数据结构
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode*> storeTreeNode;
        storeTreeNode.push(root);
        while (!storeTreeNode.empty()) {
            if (root->left) {
                storeTreeNode.push(root->left);
                root = root->left;
            } else {
                auto node = storeTreeNode.top();
                storeTreeNode.pop();
                result.push_back(node->val);
                if (node->right) {
                    storeTreeNode.push(node->right);
                    root = node->right;
                }
            }
        }
        return result;
    }
};

//方法3，迭代版，Morris Traversal算法，不需要使用额外的空间
/*
要使用O(1)空间进行遍历，最大的难点在于，遍历到子节点的时候怎样重新返回到父节点（假设节点中没有指向父节点的p指针）
由于不能用栈作为辅助空间。为了解决这个问题，Morris方法用到了线索二叉树（threaded binary tree）的概念。
在Morris方法中不需要为每个节点额外分配指针指向其前驱（predecessor）和后继节点（successor)
只需要利用叶子节点中的左右空指针指向某种顺序遍历下的前驱节点或后继节点就可以了。
*/
/*
重复以下1、2直到当前节点为空。
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点（即当前节点的左子树的最右节点）。
   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点（利用这个空的右孩子指向它的后缀）。当前节点更新为当前节点的左孩子。
   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *current = NULL, *pre = NULL;
        vector<int> res;
        current = root;
        while (current != NULL) {                 
            if(current->left == NULL) {
                res.push_back(current->val);
                current = current->right;      
            } else {
                /* Find the inorder predecessor of current */
                pre = current->left;
                while (pre->right != NULL && pre->right != current)
                    pre = pre->right;
                if (pre->right == NULL) {     /* Make current as right child of its inorder predecessor */
                    pre->right = current;
                    current = current->left;
                } else {
                /* Revert the changes made in if part to restore the original 
                tree i.e., fix the right child of predecssor */   
                    pre->right = NULL;
                    res.push_back(current->val);
                    current = current->right;      
                } 
            }
        } 
        return res;
    }
};