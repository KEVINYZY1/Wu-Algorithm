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


//二叉树，输出每行最右边的数
//bfs 非常简单明了
class Solution1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==NULL)
            return result;
        queue<TreeNode*>q1,q2;
        q1.push(root);
        while(!q1.empty()){
            auto node=q1.front();
            q1.pop();
            if(node->left)
                q2.push(node->left);
            if(node->right)
                q2.push(node->right);
            int rightNum=node->val;
            if(q1.empty()){
                q1.swap(q2);
                while(!q2.empty())
                    q2.pop();
                result.push_back(rightNum);
            }
        }
        return result;
    }
};

//dfs，按中，右，左的顺序遍历二叉树，考虑用哈希表记录谁是每一行第一个元素

