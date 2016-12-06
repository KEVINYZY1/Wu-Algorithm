#include<cstdlib>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//dfs，利用了系统栈，函数递归
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lm=minDepth(root->left);
        int rm=minDepth(root->right);
        if(lm==0&&rm==0)
            return 1;//只有一个根节点的情况
        if(lm==0)lm=INT_MAX;
        if(rm==0)rm=INT_MAX;
        return min(lm,rm)+1;//要加1，算上根节点的1
    }

//用bfs，层次遍历，若一行中有叶子节点，则深度为行数
    int minDepth2(TreeNode* root) {
       //用2个队列存储行数
        if(!root)return 0;
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(root);
        int minDepth=1;
        while(!q1.empty()){
            if(root->left==NULL&&root->right==NULL)return minDepth;
            if(root->left)q2.push(root->left);
            if(root->right)q2.push(root->right);
            q1.pop();
            if(q1.empty()){
                minDepth++;
                q1=q2;
                //q2.clear();//队列没有clear成员函数，忘了清空q2
                while(!q2.empty())q2.pop();
            }
            root=q1.front();
        }
        return minDepth;
    }