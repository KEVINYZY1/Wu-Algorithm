#include<vector>
#include<stack>

using namespace std;

//方法1，暴力解法，适当剪枝
class Solution1 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int sum=0;
        if(matrix.empty() || matrix[0].empty())
            return sum;
        const int rows=matrix.size();
        const int columns=matrix[0].size();
        vector<vector<int>>dp(rows,vector<int>(columns,0));
        //求出所有的dp值，dp[i][j]代表的意思是第i行第j列开始，该i行一共有多少个连续的1
        for(int i = 0; i < rows; i++)
            dp[i][columns-1] = (matrix[i][columns-1] == '1');
        for(int i = 0; i < rows; i++)
            for(int j = columns - 2; j >= 0; j--)
                if(matrix[i][j] == '1')
                    dp[i][j] = 1 + dp[i][j + 1];
        
        //以每个点作为矩形的左上角计算所得的最大矩形面积
        for(int i=0; i<rows; ++i){
            for(int j=0; j<columns; ++j){
                if(matrix[i][j]=='1'){
                    //剪枝，columns-j是最大宽度，rows-i是最大高度
                    if((columns-j)*(rows-i)<=sum)
                        break;
                    int width = dp[i][j];
                    for(int k = i; k < rows && width > 0; k++){
                        //剪枝,row-i是以点(i,j)为左上角的矩形的最大高度
                        if(width * (rows-i)<=sum)
                            break;
                        //计算以(i.j)为左上角，上下边缘是第i行和第k行的矩形面积
                        if(width > dp[k][j])width = dp[k][j];//矩形宽度要取从第i行到第k行宽度的最小值
                        sum = max(sum, width * (k-i+1));
                    }
                }
            }
        }
        return sum;
    }
};

//方法2，运用第84题的思想，利用辅助栈来做。
//这一题可以转化成求直方图最大面积问题，对每一行中的每个位置，计算该位置所在列向上的1的连续个数
//这样每一行中每个位置1的个数就形成了一个直方图，对每一行调用计算直方图面积的算法，就可以求出最大的面积。
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int sum=0;
        if(matrix.empty() || matrix[0].empty())
            return sum;
        const int rows=matrix.size();
        const int columns=matrix[0].size();
        stack<int>S;
        vector<int>heights(columns+1,0);
        
        for(int i=0; i<rows; ++i){
            stack<int>().swap(S);//清空栈
            bool flag = false;//防止同一height[j]被多次更新
            for(int j=0; j<=columns; ++j){//有等号
                if(j < columns && flag == false){//更新当前行第j列的height值
                    if(matrix[i][j] == '1'){
                        if(i-1 >=0 && matrix[i-1][j] == '1')
                            heights[j]++;
                        else heights[j] = 1;
                    }
                    else heights[j] = 0;
                }
                if (S.empty() || heights[j] > heights[S.top()]){
                    S.push(j);
                    flag = false;
                }
                else{
                     int tmp = S.top();
                     S.pop();
                     sum = max(sum, heights[tmp] * (S.empty() ? j : j-S.top()-1));
                     j--; //保持此次循环中j不变
                     flag = true;//height[j]已经更新，无需再次更新
                }
            }
        }
        return sum;
    }
};