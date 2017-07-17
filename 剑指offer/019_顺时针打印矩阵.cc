#include<vector>
using namespace std;

//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
//例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
        if (matrix.empty())
            return res;
        const int rows = matrix.size();
        if (matrix[0].empty())
            return res;
        const int columns = matrix[0].size();
        int circle = ((rows < columns ? rows : columns) - 1) / 2 + 1;//圈数
        int start = 0;
        while (circle > start) {
            for (int i = start; i < columns - start; ++i) {
                res.push_back(matrix[start][i]);
            }
            for (int i = start + 1; i < rows - start; ++i) {
                res.push_back(matrix[i][columns - start - 1]);
            }
            for (int i = columns - start - 2; start * 2 + 1 < rows && i >= start; --i) {
                res.push_back(matrix[rows - start - 1][i]);
            }
            for (int i = rows - start - 2; start * 2 + 1 < columns && i > start; --i) {
                res.push_back(matrix[i][start]);
            }
            start++;
        }
        return res;
    }
};