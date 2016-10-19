#include<vector>
using namespace std;

//求解数独答案，在36题判断数独是否成立的基础更进一步(假设只有一个独一无二的解)
//和八皇后问题是一个套路
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        isSolveSudoku(board);
    }
private:
    bool isSolveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=0;k<9;k++){
                        board[i][j]='1'+k;
                        //注意要回溯！关键
                        if(checkVaildPoint(board,i,j)&&isSolveSudoku(board))
                            return true;
                        board[i][j]='.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool checkVaildPoint(vector<vector<char>>& board,int x,int y){
        //行检查
        for(int i=0;i<9;i++){
            if(i!=y && board[x][i]==board[x][y])
                return false;
        }
        //列检查
        for(int i=0;i<9;i++){
            if(i!=x && board[i][y]==board[x][y])
                return false;
        }
        //块检查
        int blockX=x/3;
        int blockY=y/3;
        for(int i=blockX*3;i<blockX*3+3;i++){
            for(int j=blockY*3;j<blockY*3+3;j++){
                if((i!=x&&j!=y)&&board[i][j]==board[x][y])
                    return false;
            }
        }
        return true;
    }
};