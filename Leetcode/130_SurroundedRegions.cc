#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

//把被X包围的O改成X
//从边上的O开始遍历，所有与边上O相连的O都不能变成X（可暂时变为Y），之后再重新遍历一遍矩阵把所有O变成X，所有Y变成O。
//注意是Bfs
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        const int rows=board.size();
        if(board[0].empty())
            return;
        const int columns=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<rows;i++){
            if(board[i][0]=='O')
                q.push(make_pair(i,0));
            if(board[i][columns-1]=='O')
                q.push(make_pair(i,columns-1));
        }
        for(int j=0;j<columns;j++){
            if(board[0][j]=='O')
                q.push(make_pair(0,j));
            if(board[rows-1][j]=='O')
                q.push(make_pair(rows-1,j));
        }
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            if(board[x][y]=='Y')
                continue;
            board[x][y]='Y';
            if(x-1>0 && y!=columns-1 && y!=0)
                if(board[x-1][y]=='O')
                    q.push(make_pair(x-1,y));
            if(x+1<rows-1 && y!=columns-1 && y!=0)
                if(board[x+1][y]=='O')
                    q.push(make_pair(x+1,y));
            if(y-1>0 && x!=rows-1 && x!=0)
                if(board[x][y-1]=='O')
                    q.push(make_pair(x,y-1));
            if(y+1<columns-1 && x!=rows-1 && x!=0)
                if(board[x][y+1]=='O')
                    q.push(make_pair(x,y+1));
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(board[i][j]=='Y')
                    board[i][j]='O';
                else if(board[i][j]='O')
                    board[i][j]='X';
            }
        }
    }
};