#include<vector>
using namespace std;

class BinarySearch {
public:
    int getPos(vector<int> A, int n, int val) {
        int low = 0;
        int high = n-1;
        while (low <= high) {//注意1，要有等于号
            int mid = low + (high-low) / 2;//注意2，考虑越界
            if (A[mid] == val) {
                while (mid >= 0 && A[mid-1] == val) {//注意3，处理重复数
                    mid--;
                }
                return mid;
            }
            else if (A[mid] > val) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};