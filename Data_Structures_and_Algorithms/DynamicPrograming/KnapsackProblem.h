#include <vector>
using namespace std;

//01背包问题
int zeroOneKnapsackProblem(vector<int>& weights, vector<int>& values, int V) {
    const int len = weights.size();
    vector<vector<int> > dp(len + 1, vector<int>(V + 1));
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j <= V; ++j) {
            if (j >= weights[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[len][V];
}

//01背包问题，优化空间复杂度
int improveZeroOneKnapsackProblem(vector<int>& weights, vector<int>& values, int V) {
    const int len = weights.size();
    vector<int> dp(V + 1);
    for (int i = 1; i <= len; ++i) {
        for (int j = V; j >= weights[i - 1]; --j) {
            dp[j] = max(dp[j], dp[j - weights[i - 1]] + values[i - 1]);
        }
    }
    return dp[V];
}

//必须正好装满背包
int fullKnapsackProblem(vector<int>& weights, vector<int>& values, int V) {
    const int len = weights.size();
    //区别于01背包问题的关键
    vector<int> dp(V + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= len; ++i) {
        for (int j = V; j >= weights[i - 1]; --j) {
            if (dp[j - weights[i - 1]] != -1)
                dp[j] = max(dp[j], dp[j - weights[i - 1]] + values[i - 1]);
        }
    }
    return dp[V];
}

//完全背包问题
int completeKnapsackProblem(vector<int>& weights, vector<int>& values, int V) {
    const int len = weights.size();
    vector<int> dp(V + 1);
    for (int i = 1; i <= len; ++i) {
        for (int j = weights[i - 1]; j <= V; ++j) {
            dp[j] = max(dp[j], dp[j - weights[i - 1]] + values[i - 1]);
        }
    }
    return dp[V];
}

//多重背包问题
int mutilKnapsackProblem(vector<int>& weights, vector<int>& values, vector<int>& num, int V) {
    const int len = weights.size();
    vector<vector<int> > dp(len + 1, vector<int>(V + 1));
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j <= V; ++j) {
            //这一步可以改进
            for (int k = 0; k <= num[i - 1]; ++k) {
                if (j >= k * weights[i - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * weights[i - 1]] + k * values[i - 1]);
                } else break;
            }
        }
    }
    return dp[len][V];
}