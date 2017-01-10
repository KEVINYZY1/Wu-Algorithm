#include<cstdlib>
#include<stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        root_=root;
        while(root!=NULL){
            s_.push(root);
            root=root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(s_.empty())
            return false;
        else return true;
    }

    /** @return the next smallest number */
    int next() {
        auto node=s_.top();
        int min=node->val;
        s_.pop();
        if(node->right){
            s_.push(node->right);
            node=node->right;
            while(node->left){
                s_.push(node->left);
                node=node->left;
            }
        }
        
        return min;
    }
private:
    TreeNode *root_;
    stack<TreeNode*> s_;
};