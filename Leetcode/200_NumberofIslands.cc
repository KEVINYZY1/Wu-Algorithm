#include<vector>
using namespace std;

//二维矩阵只包含0和1，判断只含1的区域有多少(上下左右相连为同一区域)
//dfs
class Solution1 {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        if(grid[0].empty())
            return 0;
        const int rows=grid.size();
        const int columns=grid[0].size();
        int count=0;
        vector<vector<bool>> b(rows, vector<bool>(columns,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]=='1' && b[i][j]==false){
                    count++;
                    b[i][j]=true;
                    dfs(grid, b, i, j);
                }
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &b, int i, int j){
        if(i-1>=0){
            if(b[i-1][j]==false){
                b[i-1][j]=true;
                if(grid[i-1][j]=='1')
                    dfs(grid, b, i-1, j);
            }
        }
        if(i+1<grid.size()){
            if(b[i+1][j]==false){
                b[i+1][j]=true;
                if(grid[i+1][j]=='1')
                    dfs(grid, b, i+1, j);
            }
        }
        if(j-1>=0){
            if(b[i][j-1]==false){
                b[i][j-1]=true;
                if(grid[i][j-1]=='1')
                    dfs(grid, b, i, j-1);
            }
        }
        if(j+1<grid[0].size()){
            if(b[i][j+1]==false){
                b[i][j+1]=true;
                if(grid[i][j+1]=='1')
                    dfs(grid, b, i, j+1);
            }
        }
    }
};


//unionfind
class Solution2 {
public:
    //class unionFind;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        if(grid[0].empty())
            return 0;
        const int rows=grid.size();
        const int columns=grid[0].size();
        
        unionFind uf(grid);
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]=='1'){
                    if (j!=columns-1 && grid[i][j+1]=='1')
						uf.unionP(i*columns+j, i*columns+j+1);
					if (i!=rows-1 && grid[i+1][j]=='1') 
						uf.unionP(i*columns+j, (i+1)*columns+j);
                }
            }
        }
        return uf.count();
    }
private:
    class unionFind{
    private:
        vector<int> uf_;
        vector<int> weight_;
        int count_;
        int rows_;
        int columns_;
    public:
        unionFind(vector<vector<char>>& grid){
            if(grid.empty())
                return;
            if(grid[0].empty())
                return;
            rows_=grid.size();
            columns_=grid[0].size();
            for (int i=0; i<rows_; i++) {  
                for (int j=0; j<columns_; j++) {  
                    if (grid[i][j]=='1') {
                        int id = i *columns_ + j;
                        uf_.push_back(id);
                        weight_.push_back(1);
                        count_++;
                    }
                    else{
                        uf_.push_back(0);
                        weight_.push_back(0);
                    }
                }  
            }  
        }
        int count(){
            return count_;
        }
        int find(int p){
            int temp=p;
            while(uf_[p]!=p)
                p=uf_[p];
            //在这里路径压缩！！
            while(temp != uf_[p]){
                int tempId = uf_[temp];
                uf_[temp] = uf_[p];
                temp = tempId;
            }
            return p;
        }
        void unionP(int p, int q){
            int pRoot=find(p);
            int qRoot=find(q);
            if(pRoot==qRoot)
                return;
            int allWeight=weight_[pRoot]+weight_[qRoot];
            //每次比较union大小，只比较根在weight_数组中的值
            if(weight_[pRoot]<weight_[qRoot]){
                uf_[pRoot]=qRoot;
                weight_[qRoot]=allWeight;
            }
            else{
                uf_[qRoot]=pRoot;
                weight_[pRoot]=allWeight;
            }
            count_--;
        }
    };
};