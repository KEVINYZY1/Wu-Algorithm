/*
推箱子
时间限制：1秒
空间限制：32768K
大家一定玩过“推箱子”这个经典的游戏。具体规则就是在一个N*M的地图上，有1个玩家、1个箱子、1个目的地以及若干障碍，其余是空地。玩家可以往上下左右4个方向移动，但是不能移动出地图或者移动到障碍里去。如果往这个方向移动推到了箱子，箱子也会按这个方向移动一格，当然，箱子也不能被推出地图或推到障碍里。当箱子被推到目的地以后，游戏目标达成。现在告诉你游戏开始是初始的地图布局，请你求出玩家最少需要移动多少步才能够将游戏目标达成。 
输入描述:
每个测试输入包含1个测试用例
第一行输入两个数字N，M表示地图的大小。其中0<N，M<=8。
接下来有N行，每行包含M个字符表示该行地图。其中 . 表示空地、X表示玩家、*表示箱子、#表示障碍、@表示目的地。
每个地图必定包含1个玩家、1个箱子、1个目的地。


输出描述:
输出一个数字表示玩家最少需要移动多少步才能将游戏目标达成。当无论如何达成不了的时候，输出-1。

输入例子:
4 4
....
..*@
....
.X..
6 6
...#..
......
#*##..
..##.#
..X...
.@#...

输出例子:
3
11
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct q{//分别存放人的坐标和箱子的坐标
    int x, y, xb, yb;
 	q(int x, int y, int xb, int yb):x(x),y(y),xb(xb),yb(yb)
    	{}
};
//适当使用全局变量
int b[8][8][8][8];//下标对应人的坐标和箱子的坐标，值是走的步数，全局数组，自动被初始化成0了
int l[]={0,0,1,-1},r[]={1,-1,0,0};
int personX, personY;
int boxX, boxY;
int directionX, directionY;
//
int bfs(queue<q> &p, vector<string> &v){
    b[personX][personY][boxX][boxY] = 1;
    q first(personX, personY, boxX, boxY);
    p.push(first);
    const int N = v.size();
    const int M = v[0].size();
    while(!p.empty()){
        auto temp = p.front();
        p.pop();
        if(temp.xb == directionX && temp.yb == directionY)
            return b[temp.x][temp.y][temp.xb][temp.yb]-1;
        //bfs核心
        for(int i = 0; i < 4; i++){
            int nextX = temp.x + l[i];
            int nextY = temp.y + r[i];
            //判断人下上下左右走一步后，是不是出地图，或者遇到障碍物了
            if(nextX<0 || nextX >=N || nextY<0 || nextY>=M || v[nextX][nextY]=='#')
                continue;
            //判断遇到箱子没
            if(nextX == temp.xb && nextY == temp.yb){
                int nextBX = nextX + l[i];
                int nextBY = nextY + r[i];
                //看看箱子能不能被人推，不能就拉倒
                if(nextBX<0 || nextBX >=N || nextBY<0 || nextBY>=M || v[nextBX][nextBY]=='#')
                	continue;
                //核心，判断之前bfs到没到过这里，如果到过了，说明不是最短路径
                if(b[nextX][nextY][nextBX][nextBY])
                    continue;
                b[nextX][nextY][nextBX][nextBY] = b[temp.x][temp.y][temp.xb][temp.yb] + 1;
                q cool(nextX, nextY, nextBX, nextBY);
                p.push(cool);
            }
            else{
                if(b[nextX][nextY][temp.xb][temp.yb])
                    continue;
                b[nextX][nextY][temp.xb][temp.yb] = b[temp.x][temp.y][temp.xb][temp.yb] + 1;
                q cool(nextX, nextY, temp.xb, temp.yb);
                p.push(cool);
            }
        }
    }
    return -1;
}
int main(){
    int N, M;
    while(cin >> N >> M){//一个测试用例不止一个地图，需要注意
        vector<string> v(N);
        for(int i = 0; i < N; i++){
            cin >> v[i];
        }
        //遍历，找出箱子，目的地和人的位置
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(v[i][j] == '*'){
                    boxX = i;
                    boxY = j;
                }
                else if(v[i][j] == 'X'){
                    personX = i;
                    personY = j;
                }
                else if(v[i][j] == '@'){
                    directionX = i;
                    directionY = j;
                }
            }
        }
        queue<q> p;
        cout << bfs(p, v) << endl;
    }
}