#include<cstdlib>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//把二叉树展开成链表
//方法1，在前序遍历的基础上，把所有节点按前序顺序保存，然后依次修改。不好
class Solution1 {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> result;
        if(!root)
            return;
        stack<TreeNode*>storeTreeNode;
        storeTreeNode.push(root);
        TreeNode* lastRoot=NULL;
        while(!storeTreeNode.empty()){
            //这里要记录root的是否变化，不然的话，会重复记录节点的值。
            if(lastRoot!=root){
                result.push_back(root);
                lastRoot=root;
            }
            if(root->left){
                storeTreeNode.push(root->left);
                root=root->left;
            }
            else{
                auto node=storeTreeNode.top();
                storeTreeNode.pop();
                if(node->right){
                    storeTreeNode.push(node->right);
                    root=node->right;
                }
            }
        }
        for(int i=0; i<result.size()-1; i++){
            result[i]->left=NULL;
            result[i]->right=result[i+1];
        }
        result[result.size()-1]->left=NULL;
        result[result.size()-1]->right=NULL;
    }
};

//方法2，好方法
/*
这个方法是从根节点开始出发，先检测其左子结点是否存在，如存在则将根节点和其右子节点断开，
将左子结点及其后面所有结构一起连到原右子节点的位置，把原右子节点连到元左子结点最后面的右子节点之后。
*/
class Solution2 {
public:
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *p = cur->left;
                while (p->right) p = p->right;
                p->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};