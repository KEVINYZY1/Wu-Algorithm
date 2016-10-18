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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        recursionPostorderTraversal(result,root);
        return result;
    }
    void recursionPostorderTraversal(vector<int>&result,TreeNode* root){
        if(!root)
            return;
        if(root->left)
            recursionPostorderTraversal(result,root->left);
        if(root->right)
            recursionPostorderTraversal(result,root->right);
        result.push_back(root->val);
    }
};

//方法2，迭代版，更有难度，用了一个栈作为辅助数据结构
 /*
 对于任一节点P，
1）先将节点P入栈；
2）若P不存在左孩子和右孩子，或者P存在左孩子或右孩子，但左右孩子已经被输出，则可以直接输出节点P，并将其出栈，
将出栈节点P标记为上一个输出的节点，再将此时的栈顶结点设为当前节点；
3）若不满足2）中的条件，则将P的右孩子和左孩子依次入栈，当前节点重新置为栈顶结点，之后重复操作2）；
4）直到栈空，遍历结束。
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        stack<TreeNode*>storeTreeNode;
        storeTreeNode.push(root);
        TreeNode* alreadyGet=NULL;//用来记录存在左右子树的节点，是否已经遍历了它的左右子树
        while(!storeTreeNode.empty()){
            root=storeTreeNode.top();
            if((root->left==NULL&&root->right==NULL)||(alreadyGet!=NULL&&(root->left==alreadyGet ||root->right==alreadyGet))){
                storeTreeNode.pop();
                result.push_back(root->val);
                alreadyGet=root;
            }
            else{
                //注意是右左孩子节点依次入栈，注意顺序
                if(root->right)
                    storeTreeNode.push(root->right);
                if(root->left)
                    storeTreeNode.push(root->left);
            }
        }
        return result;
    }
};