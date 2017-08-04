#include<vector>
using namespace std;


//将二维矩阵顺时针90度旋转，要求做到in-place
//想到rotateArray那一题，都是分几步来处理原数组，得到最终结果
//这里矩阵需要先转置，然后再对折即可
class Solution {
public: 
    void rotate(vector<vector<int> >& matrix) {
        const int n = matrix.size();
        //沿主对角线对折
        for (int k = 0, j = 0; k < n - 1; ++k, ++j) {
            for (int i = 0; i < n - 1 - j; ++i) {
                swap(matrix[k][i], matrix[n - 1 - i][n - 1 - k]);
            }
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
private:
    void swap(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }
};