#include <vector>
#include <string>
#include <complex>
using namespace std;

//皇后问题，用回溯法穷举出所有解
//有一定技巧，就是一行放了一个皇后之后，就立即转下一行
//以及单独维护一个数组，来快速判断是否可以安放皇后
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<string> solution(n, string(n, '.'));
        vector<int> site;//用一个数组记录安放Q的位置,这样可以快速判断是否可以安放皇后
        findNQueues(n, 0, site, solution);
        return result;
    }
private:
    vector<vector<string> > result;
    void findNQueues(int n, int row, vector<int> &site, vector<string> &solution) {
        if (n == row) {
            result.push_back(solution);
            return;
        }
        for (int i = 0; i < solution.size(); i++) {
            if (solution[row][i] == '.') {
                solution[row][i] = 'Q';
                site.push_back(i);
                if (isNoAttack(site, solution, row, i)) {
                    findNQueues(n, row + 1, site, solution);
                }
                solution[row][i] = '.';
                site.pop_back();
            }
        }
        return;
    }
    bool isNoAttack(vector<int> &site, vector<string> &solution, int x, int y) {
        for (int i = 0; i < site.size() - 1; i++) {
            if (y == site[i] || abs(x - i) == abs(y - site[i]))
                return false;
        }
        return true;
    }
};
