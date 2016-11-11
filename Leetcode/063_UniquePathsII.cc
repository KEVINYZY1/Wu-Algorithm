#include<vector>
using namespace std;

//加了障碍
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        if(obstacleGrid[0].empty())
            return 0;
        if(obstacleGrid[0][0]==1)//出发点就是障碍，智障吧
            return 0;
        //将第一行和第一列设置一下，注意一旦有障碍物，则都置0
        for(int i=0;i<obstacleGrid.size();i++){
            if(obstacleGrid[i][0]==0)
                obstacleGrid[i][0]=1;
            else {
                obstacleGrid[i][0]=0;
                while(i<obstacleGrid.size()){
                    obstacleGrid[i][0]=0;
                    i++;
                }
            }
        }
        for(int i=1;i<obstacleGrid[0].size();i++){
            if(obstacleGrid[0][i]==0)
                obstacleGrid[0][i]=1;
            else {
                obstacleGrid[0][i]=0;
                while(i<obstacleGrid[0].size()){
                    obstacleGrid[0][i]=0;
                    i++;
                }
            }
        }
        //开始处理obstacleGrid
        int m=0,n=0;
        for(m=1;m<obstacleGrid.size();m++){
            for(n=1;n<obstacleGrid[0].size();n++){
                if(obstacleGrid[m][n]==1)//有障碍
                    obstacleGrid[m][n]=0;
                else obstacleGrid[m][n]=obstacleGrid[m-1][n]+obstacleGrid[m][n-1];
            }
        }
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};