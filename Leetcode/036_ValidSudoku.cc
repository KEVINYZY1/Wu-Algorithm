#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //需要优化
        unordered_set<char> hor[9];
        unordered_set<char> ver[9];
        unordered_set<char> sqr[3][3];
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c != '.') {
                    if(ver[j].find(c) != ver[j].end()) return false;
                    if(hor[i].find(c) != hor[i].end()) return false;
                    if(sqr[i / 3][ j / 3].find(c) != sqr[i / 3][j / 3].end()) return false;
                    ver[j].insert(c);
                    hor[i].insert(c);
                    sqr[i / 3][j / 3].insert(c);
                }
            }
        }
        return true;
    }
};
    