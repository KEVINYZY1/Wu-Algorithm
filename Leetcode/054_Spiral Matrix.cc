#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        const int rows=matrix.size();
        if(rows==0)
            return result;
        const int columns=matrix[0].size();
        int x1=0,y1=0;
        int x2=rows-1,y2=columns-1;
        if(rows==1)//只有一行
            return matrix[0];
        if(columns==1){//只有一列
            for(int i=0;i<rows;++i){
                result.push_back(matrix[i][0]);
            }
            return result;
        }
        while(x1<x2||y1<y2){//正常搞，一圈一圈来
            for(int k=0;k<y2-y1;++k){
                result.push_back(matrix[x1][y1+k]);
            }
            for(int k=0;k<x2-x1;++k){
                result.push_back(matrix[x1+k][y2]);
            }
            for(int k=0;k<y2-y1;++k){
                result.push_back(matrix[x2][y2-k]);
            }
            for(int k=0;k<x2-x1;++k){
                result.push_back(matrix[x2-k][y1]);
            }
            ++x1;
            ++y1;
            --x2;
            --y2;
            if(x1>x2||y1>y2)
                break;
        }
        if(x1==x2&&y1==y2)
            result.push_back(matrix[x1][y1]);
        if(result.size()>rows*columns)
            result.erase(--result.end());
        return result;
    }
};