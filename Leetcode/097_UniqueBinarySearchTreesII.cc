#include<cstdlib>
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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return vector<TreeNode*>();
        return findTrees(1, n);
    }
private:
    vector<TreeNode *> findTrees(int min, int max) {
        vector<TreeNode *> ret;
        if(min>max) {
            ret.push_back(NULL);
            return ret;
        }
        for(int i=min; i<=max; i++) {
            vector<TreeNode*> leftSubTree = findTrees(min,i-1);
            vector<TreeNode*> rightSubTree = findTrees(i+1,max);
            for(int j=0; j<leftSubTree.size(); j++) {
                for(int k=0; k<rightSubTree.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftSubTree[j];
                    root->right = rightSubTree[k];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};