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

  
//还是类似于层次遍历，输出每一层，只不过偶数层是逆序输出
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        queue<TreeNode*> q1, q2;//两个队列，用来区分不同的层
        q1.push(root);
        vector<int>temp;
        int countRows=1;
        do{
            auto node=q1.front();
            q1.pop();
            temp.push_back(node->val);
            if(node->left)
                q2.push(node->left);
            if(node->right)
                q2.push(node->right);
            if(q1.empty()){
                q1=q2;
                while(!q2.empty())//queue没有clear函数，手动清空q2
                    q2.pop();
                if(countRows%2==0)
                    reverse(temp.begin(),temp.end());
                countRows++;
                result.push_back(temp);
                temp.clear();
            }
        }while(!q1.empty());
        return result;
    }
};