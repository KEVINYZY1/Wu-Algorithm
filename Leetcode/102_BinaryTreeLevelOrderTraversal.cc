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

//二叉树层次遍历，利用队列，不过为了按照题目要求，区分每一层的节点数据，使用了两个队列
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        queue<TreeNode*>q1;//建立可以容纳树节点指针的队列
        if(root==NULL)return result;
        //如何将val按每层存放！
        vector<int>temp;
        q1.push(root);
        do{
            queue<TreeNode*>q2;
            while(!q1.empty()){
                root=q1.front();
                q1.pop();
                temp.push_back(root->val);
            if(root->left){
                q2.push(root->left);
            }
            if(root->right){
                q2.push(root->right);
            }
            }
            result.push_back(temp);
            temp.clear();
            q1=q2;
        }while(!q1.empty());
        return result;
    }
};