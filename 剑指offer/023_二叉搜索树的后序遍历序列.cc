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

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes,否则输出No。
//假设输入的数组的任意两个数字都互不相同。

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;
		return helper(sequence, 0, sequence.size() - 1);
    }
private:
    bool helper(vector<int>& sequence, int start, int end){
        if (start >= end)
            return true;
        int p = sequence[end];
        int storeStart = start;
        //找出右子树
        while (sequence[start] < sequence[end]) {
            start++;
        }
        //检查右子树
        for (int i = start; i < end; i++) {
            if (sequence[i] < sequence[end])
                return false;
        }    
        //递归检查
        return helper(sequence, storeStart, start - 1) && helper(sequence, start, end - 1);
    }
};