#include<vector>
using namespace std;

//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
//例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>res;
        if(matrix.empty())
            return res;
        const int rows=matrix.size();
        if(matrix[0].empty())
            return res;
        const int columns=matrix[0].size();
        int circle=((rows<columns?rows:columns)-1)/2+1;//圈数
        for(int i=0;i<circle;i++){
            //从左向右打印
            for(int j=i;j<columns-i;j++)
                res.push_back(matrix[i][j]);         
            //从上往下的每一列数据
            for(int k=i+1;k<rows-i;k++)
                res.push_back(matrix[k][columns-1-i]);
            //判断是否会重复打印(从右向左的每行数据)
            for(int m=columns-i-2;(m>=i)&&(rows-i-1!=i);m--)//多个判断，判断会不会之前的从左向右打印的行重合。
                res.push_back(matrix[rows-i-1][m]);
            //判断是否会重复打印(从下往上的每一列数据)
            for(int n=rows-i-2;(n>i)&&(columns-i-1!=i);n--)
                res.push_back(matrix[n][i]);
        }
        return res;
    }
};