#include<vector>
#include<stack>

using namespace std;

//从一个数组中找出一个子数组，其元素大小按子数组中最小值计算，要求和最大
//方法1，暴力解法，有可以剪枝的地方，就是每次对一个高度开始向右边遍历时候，先找到右边中heights[k]>heights[k-1]的地方
//然后从k开始遍历


//方法2，利用栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxRectangle=0;
        if(heights.empty())
            return maxRectangle;
        heights.push_back(0);//保证哪怕heights都是的递增的，最后也会触发计算
        stack<int>index;
        for(int i=0; i<heights.size(); i++){
            if(index.empty() || heights[i]>heights[index.top()])
                index.push(i);
            else{
                int tempIndex=index.top();
                index.pop();
                maxRectangle=max(maxRectangle, heights[tempIndex]*(index.empty()? i: i-1-index.top()));
                i--;
            }
        }
        return maxRectangle;
    }
};