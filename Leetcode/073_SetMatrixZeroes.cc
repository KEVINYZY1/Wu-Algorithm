#include<vector>
using namespace std;

//这个题目用O(mn)时间 O(1)空间。O(mn)时间很好理解。就是说每个数字都得走一边。
//实现O(1)空间用到得技巧就是我们用第一行和第一列来记录这某一行或某一列该不该变成0。
//比如如果matrix[i][j]是0，那么我们就把matrix[0][j]和matrix[i][0]变为0，
//到时候只要查看这两个数就可以知道i行和j列应该变为0。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int rows=matrix.size();
        if(rows==0)return;
        const int columns=matrix[0].size();
        int zerorow0=1,zerocolumn0=1;
        for(int i=0;i<columns;++i){
            if(matrix[0][i]==0){
                zerorow0=0;
                break;
            }
        }
        for(int i=0;i<rows;++i){
            if(matrix[i][0]==0){
                zerocolumn0=0;
                break;
            }
        }
        for(int i=1;i<rows;++i){
            for(int j=1;j<columns;++j){
                if(matrix[i][j]==0){
                matrix[0][j]=0;
                matrix[i][0]=0;
               // break;//跳出最内层的循环！！
            }
        }
        }
        for(int i=1;i<columns;++i){
            if(matrix[0][i]==0){
                for(int j=1;j<rows;++j){
                    matrix[j][i]=0;
                }
            }
        }
        for(int i=1;i<rows;++i){
            if(matrix[i][0]==0){
                for(int j=1;j<columns;++j){
                    matrix[i][j]=0;
                }
            }
        }
        if(zerorow0==0){
            for(int i=0;i<columns;++i){
                matrix[0][i]=0;
            }
        }
        if(zerocolumn0==0){
            for(int i=0;i<rows;++i){
                matrix[i][0]=0;
            }
        }
    }
};