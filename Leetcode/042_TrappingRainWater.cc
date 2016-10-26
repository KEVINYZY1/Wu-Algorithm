#include<vector>
using namespace std;


//方法1，找出数组最大点，然后从两边向最大点遍历数组，如果从左边遍历到最大点，左边开始经历的第二小点就是容纳水的顶高度。
class Solution1 {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;
        int max = -1, maxInd = 0;
        int i = 0;
        for(; i < height.size(); ++i){
            if(height[i] > max){
                max = height[i];
                maxInd = i;
            }
        }
        int area = 0, root = height[0];
        for(i = 0; i < maxInd; ++i){
            if(root < height[i]) root = height[i];
            else area += (root - height[i]);
        }
        for(i = height.size()-1, root = height[height.size()-1]; i > maxInd; --i){
            if(root < height[i]) root = height[i];
            else area += (root - height[i]);
        }
        return area;
    }
};

//方法2，每个点能盛放水的大小，是由它左右临近的最大值中的最小值决定的。
//找出两个数组，一个依次放入从左边开始的最大值，一个从右边。
class Solution2{
public:
    int trap(vector<int>& height) {
        if(height.size() < 2) return 0;  
        int sz = height.size();  
        vector<int> left(sz, 0);  
        vector<int> right(sz, 0);  
        for(int i = 1; i < sz; i++){  
            left[i] = max(left[i-1], height[i-1]);  
            right[sz-i-1] = max(right[sz-i], height[sz-i]);  
        }  
        int water = 0;  
        for(int i = 1; i < sz; i++){  
            int minh = min(left[i],right[i]);  
            water += minh > height[i] ? minh - height[i] : 0;  
        }  
        return water;  
    }
};