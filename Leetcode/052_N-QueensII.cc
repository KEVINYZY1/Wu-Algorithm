#include<vector>
#include<string>
#include <complex>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<string> solution(n, string(n, '.'));
        vector<int> site;//用一个数组记录安放Q的位置,这样可以快速判断是否可以安放皇后
        findNQueues(n, 0, site, solution, result);
        return result;
    }
private:
    void findNQueues(int n, int row, vector<int> &site, vector<string> &solution, int &result) {
        if (n == row) {
            result++;
            return;
        }
        for (int i = 0; i < solution.size(); i++) {
            if (solution[row][i] == '.') {
                solution[row][i] = 'Q';
                site.push_back(i);
                if (isNoAttack(site, solution, row, i)) {
                    findNQueues(n, row + 1, site, solution, result);
                }
                solution[row][i] = '.';
                site.pop_back();
            }
        }
        return;
    }
    bool isNoAttack(vector<int> &site, vector<string> &solution, int x, int y){
        for (int i = 0; i < site.size() - 1; i++) {
            if (y == site[i] || abs(x - i) == abs(y - site[i]))
                return false;
        }
        return true;
    }
};
