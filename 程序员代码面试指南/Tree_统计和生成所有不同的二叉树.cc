#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}    
};

//根据整数N代表的中序遍历结果{1，2，3...N} 来生成不同可能的二叉树结构
//中序遍历有序，那么二叉树为搜索二叉树，任意一个数字i做根节点，那么可能有num(i-1)*num(N-i)个结果
int getSum(int N) {
    if (N <= 0)
        return 0;
    vector<int> dp(N + 1);
    dp[0] = 1;
    //dp[N - 1] = 1;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < i + 1; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
}

int generateTrees(int N) {
    
}

int main () {
    TreeNode
}