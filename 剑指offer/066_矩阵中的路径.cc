#include<vector>
using namespace std;

//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
//如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
//例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bccced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        if (str == NULL || rows <= 0 || cols <= 0)
            return false;
        bool *isOk = new bool[rows * cols]();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                  if (isHsaPath(matrix, rows, cols, str, isOk, i, j))
                    return true;
        }
        return false;
    }
private:
    bool isHsaPath(char *matrix, int rows, int cols, char *str, bool *isOk, int curx, int cury) {
        if (*str == '\0')
              return true;
        if (cury == cols) {
              curx++;
              cury = 0;
        }
        if (cury == -1) {
              curx--;
              cury = cols - 1;
        }
        if (curx < 0 || curx >= rows)
            return false;
        if (isOk[curx * cols + cury] || *str != matrix[curx * cols + cury])
            return false;
        isOk[curx * cols + cury] = true;
        bool sign = isHsaPath(matrix, rows, cols, str + 1, isOk, curx - 1, cury)
            ||isHsaPath(matrix, rows, cols, str + 1, isOk, curx + 1, cury)
            ||isHsaPath(matrix, rows, cols, str + 1, isOk, curx, cury - 1)
            ||isHsaPath(matrix, rows, cols, str + 1, isOk, curx, cury + 1);
        isOk[curx * cols + cury] = false;
        return sign;
    }

};