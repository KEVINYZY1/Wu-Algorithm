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

//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode *pLastofTree = NULL;
        buildList(pRootOfTree, pLastofTree);
        while (pLastofTree && pLastofTree->left) {
            pLastofTree = pLastofTree->left;
        }
        return pLastofTree;
    }
private:
    void buildList(TreeNode* pRootOfTree, TreeNode* &pLastofTree) {
        if (pRootOfTree == NULL)
            return;
        if (pRootOfTree->left)
            buildList(pRootOfTree->left, pLastofTree);
		if (pLastofTree)
        	pLastofTree->right = pRootOfTree;
        pRootOfTree->left = pLastofTree;
        pLastofTree = pRootOfTree;//这句别忘
        if (pRootOfTree->right)
            buildList(pRootOfTree->right, pLastofTree);
    }
};