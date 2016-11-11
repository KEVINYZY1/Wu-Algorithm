#include<vector>
using namespace std;

//方法1，回溯法，超时
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;  
        return uniquePaths(m-1, n) + uniquePaths(m, n-1); 
    }
};

//方法2，动态规划，建立一个m*n的表
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if(m<=0 || n<=0) return 0;  
        vector<vector<int> > table(m, vector<int>(n, 1));  
        for (int i = 1; i < m; i++)  {  
            for (int j = 1; j < n; j++)  {  
                table[i][j] = table[i-1][j] + table[i][j-1];  
            }  
        }  
        return table[m-1][n-1]; 
    }
};