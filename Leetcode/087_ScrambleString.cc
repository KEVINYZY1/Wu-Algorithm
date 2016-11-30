#include<vector>
#include<string>

using namespace std;

//s1的一部分子字符串逆序，变成s2
class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int len1=s1.size();
        const int len2=s2.size();
        if(len1 != len2)
            return false;
        // f[l][i][j]用来存储scramble(l, i, j)的结果
        //bool scramble(l, i, j)，表示“s1从位置i开始长度为l的子串”能否经由scramble操作变为“s2从位置j开始长度为l的子串”
        vector<vector<vector<bool>>> f(len2 + 1, vector<vector<bool>>(len2, vector<bool>(len2, 0)));
        // 计算l==1的边界情况
        for (int i = 0; i < len1; i++)
            for (int j = 0; j < len1; j++)
                f[1][i][j] = (s1[i] == s2[j]);
        // 按照l从小到大的顺序枚举子问题
        for (int l = 1; l <= len1; l ++)
            for (int i = 0; i + l <= len1; i++)
                for (int j = 0; j + l <= len1; j++)
                    // 枚举其划分方案
                    for (int k = 1; k < l; k++) {
                        //状态方程
                        f[l][i][j] = f[l][i][j] | (f[k][i][j + l - k] && f[l - k][i + k][j]) 
                                                | (f[k][i][j] && f[l - k][i + k][j + k]);
                                            // 枚举是否进行交换
                    }
        // 返回答案
        return f[len1][0][0];
    }
};