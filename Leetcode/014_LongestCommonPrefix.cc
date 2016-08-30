#include<string>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int length=strs.size();
        if(length==1)return strs[0];
        string result;
        int minSubLength=INT_MAX;//注意别出错
        for(int i=0; i<length;i++){
            int size=strs[i].size();
            //这里模板函数要求类型必须一致，没有隐式类型转换
            minSubLength=min(size,minSubLength);
        }
        if (minSubLength==INT_MAX)return result;
        for(int i=0; i<minSubLength;i++){
            for(int j=1; j<length;j++){
                if(strs[j-1][i]!=strs[j][i])return result;
                if(j==length-1)result+=strs[j][i];
            }
        }
        return result;
    }
};