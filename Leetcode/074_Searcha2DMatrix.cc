#include<vector>
using namespace std;

//这是一个杨氏矩阵。算法导论第6章思考题第三题的最后一问提到！！
//因为矩阵是行有序并且列有序，查找只需要先按行查找，定位出在哪一行之后再进行列查找即可，所以就是进行两次二分查找。时间复杂度是O(logm+logn)
//空间上只需两个辅助变量，因而是O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows=matrix.size();
        if(!rows)return false;
        const int columns=matrix[0].size();
        int low=0,high=rows-1;
        int left=0,right=columns-1;
        //先确定块
        while(low<high){
            int mid=low+(high-low)/2;
            if(target<matrix[mid][left]){
                high=mid-1;
            }
            else if(target>matrix[mid][right]){
                low=mid+1;
            }
            else break;
        }
        int mid=low+(high-low)/2;
        if(target<matrix[mid][left]||target>matrix[mid][right])return false;
        //对块二分查找
        while(left<=right){
            int middle=left+(right-left)/2;
            if(target==matrix[mid][middle])return true;
            else if(target>matrix[mid][middle])left=middle+1;
            else if(target<matrix[mid][middle])right=middle-1;
        }
        return false;
    }
};