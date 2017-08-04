#include<vector>
using namespace std;
//这是一个杨氏矩阵。算法导论第6章思考题第三题的最后一问提到！！

//从矩阵右上角到左下角依次和target比较，这样时间复杂度是O(m+n),如果从左上角到右下角，则是指数级别的时间复杂度
//因为右上到左下，有递增递减两个方向，可以做出选择。而左上到右下则不可以
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        const int rows = matrix.size();
        if (!rows)
            return false;
        const int colunms = matrix[0].size();
        int x = 0, y = colunms - 1;//右上角
        while (x < rows && y >= 0) {
            if (matrix[x][y] > target) {
                y--;
            } else if (matrix[x][y] < target) {
                x++;
            } else {
                return true;
            }
        }
        return false;
    }
};