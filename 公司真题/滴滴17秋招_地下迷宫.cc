/*
小青蛙有一天不小心落入了一个地下迷宫,小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。为了让问题简单,假设这是一个n*m的格子迷宫,迷宫每个位置为0或者1,0代表这个位置有障碍物,小青蛙达到不了这个位置;1代表小青蛙可以达到的位置。小青蛙初始在(0,0)位置,地下迷宫的出口在(0,m-1)(保证这两个位置都是1,并且保证一定有起点到终点可达的路径),小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值,向上爬一个单位距离需要消耗3个单位的体力值,向下移动不消耗体力值,当小青蛙的体力值等于0的时候还没有到达出口,小青蛙将无法逃离迷宫。现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0,m-1)位置)。 
输入描述:
输入包括n+1行:

第一行为三个整数n,m(3 <= m,n <= 10),P(1 <= P <= 100)

接下来的n行:

每行m个0或者1,以空格分隔


输出描述:
如果能逃离迷宫,则输出一行体力消耗最小的路径,输出格式见样例所示;如果不能逃离迷宫,则输出"Can not escape!"。
测试数据保证答案唯一

输入例子:
4 4 10
1 0 0 1
1 1 0 1
0 1 1 1
0 0 1 1

输出例子:
[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]
*/

#include <iostream>
#include <vector>
using namespace std;
 
int Maze[10][10];
 
#define VISITED 2
 
int m, n, P;
int Dir[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
int Cost[4] = { -1, -1, -3, 0 };
int H = -200;
 
struct MazePoint {
    MazePoint(int _x, int _y)
    :x(_x), y(_y) {
 
    }
    int x, y;
};
 
vector<MazePoint> PathStack;
vector<MazePoint> MinCostPath;
 
void PushPoint(int x, int y){
    PathStack.push_back(MazePoint(x, y));
}
 
void PopPoint() {
    PathStack.pop_back();
}
 
void PrintPath(const vector<MazePoint>& Path) {
    for (int i = 0; i < Path.size(); ++i) {
        cout << "[" << Path[i].x << "," << Path[i].y << "]";
        if (i < Path.size() - 1) {
            cout << ",";
        }
    }
}
 
void Search(int x, int y, int currP) {
    PushPoint(x, y);
    Maze[x][y] = VISITED;
 
    if (x == 0 && y == m-1 && currP >= 0) {
        if (currP > H) {
            H = currP;
            MinCostPath = PathStack;
        }
        //恢复！
        PopPoint();
        Maze[x][y] = 1;
        return;
    }
     
    if(currP > 0) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + Dir[i][0];
            int ny = y + Dir[i][1];
            int nP = currP + Cost[i];
            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                Maze[nx][ny] == 1) {
                Search(nx, ny, nP);
            }
        }
    }
    //回溯完了要复原！
    PopPoint();
    Maze[x][y] = 1;
}
 
int main() {
    cin >> n >> m >> P;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> Maze[i][j];
        }
    }
    Search(0, 0, P);
    if (H != -200) {
        PrintPath(MinCostPath);
    }
    else {
        cout << "Can not escape!";
    }
    return 0;
}
