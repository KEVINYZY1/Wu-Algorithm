#include<vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if (array.empty())
            return result;
        int start = 0;
        int end = array.size() - 1;
        while (start < end) {
            int s = array[start] + array[end];
            if (s == sum) {
                result.push_back(array[start]);
                result.push_back(array[end]);
                return result;
            } else if (s > sum) {
                end--;
            } else {
                start++;
            }
        }
        return result;
    }
};