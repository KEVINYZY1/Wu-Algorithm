#include<vector>
using namespace std;
//双指针法
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.empty())
            return 0;
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int tempArea = min(height[left], height[right]) * (right - left);
            if (height[left] > height[right])
                right--;
            else left++;
            maxArea = max(maxArea, tempArea);
        }
        return maxArea;
    }
};