#include<vector>
using namespace std;

//输入的数组必然有唯一解
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2,0);
        int start=0;
        int end=numbers.size()-1;
        while(start<end){
            int sum=numbers[start]+numbers[end];//严格来说，sum的值有可能溢出，需要注意一下
            if(sum>target)
                end--;
            else if(sum<target)
                start++;
            else {
                result[0]=start+1;
                result[1]=end+1;
                return result;
            }
        }
        return result;
    }
};
