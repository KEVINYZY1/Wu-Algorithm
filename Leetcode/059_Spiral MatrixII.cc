#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>result(n,vector<int>(n,1));//!
        int elem=0;
        int loop=n/2;
        int x1=0,y1=0;int x2=n-1,y2=n-1;
        while(loop>0){
            for(int i=0;i<n-1;++i){
                result[x1][y1+i]=++elem;
            }
            for(int i=0;i<n-1;++i){
                result[x1+i][y2]=++elem;
            }
            for(int i=0;i<n-1;++i){
                result[x2][y2-i]=++elem;
            }
            for(int i=0;i<n-1;++i){
                result[x2-i][y1]=++elem;
            }
            n-=2;
            --loop;
            ++x1;++y1;
            --x2;--y2;
        }
        if(x1==x2&&y1==y2)
            result[x1][y1]=++elem;
        return result;
    }
};