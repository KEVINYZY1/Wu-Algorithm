#include<vector>
using namespace std;

//格雷码
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n<0)  
            return res;  
        if(n==0){  
            res.push_back(0);  
            return res;  
        }  
        res.push_back(0);  
        res.push_back(1);  
        for(int i=2;i<=n;i++){  
            int size = res.size();  
            for(int j=size-1;j>=0;j--)  
                res.push_back(res[j]+(1<<(i-1)));//找到n位格雷码和n-1位格雷码之间的关系  
        }  
        return res;  
    }
};