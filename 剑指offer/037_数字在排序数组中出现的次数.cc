#include<vector>
using namespace std;

//以后写二分法，都用闭区间把= =
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        const int len = data.size();
        int firstK = -1, lastK = 0;
        int low = 0, high = len - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (data[mid] < k) {
                low = mid + 1;
            } else if (data[mid] > k) {
                high = mid - 1;
            } else {
                if ((mid < len - 1 && data[mid + 1] != k) || mid == len - 1) {
                    lastK = mid;
                    break;
                } else {
                    low = mid + 1;
                }
            }
        }
        low = 0, high = len - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (data[mid] < k) {
                low = mid + 1;
            } else if (data[mid] > k) {
                high = mid - 1;
            } else {
                if ((mid > 0 && data[mid - 1] != k) || mid == 0) {
                    firstK = mid;
                    break;
                } else {
                    high = mid - 1;
                }
            }
        }
        if (firstK == -1)
            return 0;
        return lastK - firstK + 1;
    }
};