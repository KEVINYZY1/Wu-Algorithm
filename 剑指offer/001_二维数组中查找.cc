#include<vector>
using namespace std;

//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        const int rows=array.size();
        if(rows==0)
            return false;
        const int columns=array[0].size();
        if(columns ==0)
            return false;
        int start=array[0][columns-1];
        int i=0;
        int j=columns -1;
        while(i<rows && j>=0){
            if(target>array[i][j])
                i++;
            else if(target<array[i][j])
                j--;
            else return true;
        }
        return false;
    }
};