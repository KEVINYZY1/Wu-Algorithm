#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
//注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

class Solution {
public:
    //后继
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == NULL)
            return NULL;
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left != NULL) {
                pNode = pNode->left;
            }
            return pNode;
        }
        auto parent = pNode->next;
        while (parent != NULL && parent->right == pNode) {
            pNode = pNode->next;
            parent = parent->next;
        }
        if (parent != NULL)
            return parent;
        return NULL;
    }
};