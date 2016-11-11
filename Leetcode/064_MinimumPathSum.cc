#include<vector>
using namespace std;

//62,63,64都差不多
//每个点都记录所能到达自己所在处的最大和
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        if(grid[0].empty())
            return 0;
        vector<vector<int>> table(grid.size(), vector<int>(grid[0].size(),0));
        table[0][0]=grid[0][0];
        for(int i=1;i<grid.size();i++){
            table[i][0]=grid[i][0]+table[i-1][0];
        }
        for(int i=1;i<grid[0].size();i++){
            table[0][i]=grid[0][i]+table[0][i-1];
        }
        for(int m=1;m<grid.size();m++){
            for(int n=1;n<grid[0].size();n++){
                table[m][n]=min(table[m-1][n]+grid[m][n],table[m][n-1]+grid[m][n]);
            }
        }
        return table[grid.size()-1][grid[0].size()-1];
    }
};