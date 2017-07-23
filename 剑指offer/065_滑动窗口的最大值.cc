#include<vector>
using namespace std;

/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}，
 {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
		vector<int> result;
        if (num.empty() || size == 0)
            return result;
        int maxIndex = 0;
        const int len = num.size();
        if (size > len)
            return result;
        for (int i = 1; i < size; i++) {
            if (num[i] > num[maxIndex])
                maxIndex = i;
        }
        result.push_back(num[maxIndex]);
        int startIndex = 1;
        int endIndex = size;
        while (endIndex < len) {
            if (num[endIndex] >= num[maxIndex]) {
                maxIndex = endIndex;
            }
            
            else if (maxIndex < startIndex || maxIndex > endIndex) {
                maxIndex = findMaxIndex(num, startIndex, endIndex);
            }
            result.push_back(num[maxIndex]);
            startIndex++;
            endIndex++;
        }
        return result;
    }
    int findMaxIndex(const vector<int>& num, int startIndex, int endIndex) {
        int maxIndex = startIndex;
        for (int i = startIndex; i <= endIndex; i++) {
            if (num[i] >= num[maxIndex])
                maxIndex = i;
        }
        return maxIndex;
    }
};