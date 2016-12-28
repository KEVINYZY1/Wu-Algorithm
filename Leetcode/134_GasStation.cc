#include<vector>
using namespace std;

//方法1，O(n2)时间复杂度，依次下标开始尝试。
//方法2，将gas和cost数组对应相减，整合成diff数组，如果diff数组之和小于0，那么不存在解
//
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty())
            return -1;
        const int len=gas.size();

        vector<int> diff(gas.size());  
        for(int i=0; i<len; i++){  
            diff[i] = gas[i]-cost[i];  
        }  
        int startnode=0;  
        int tank=0;  
        int sum=0;  
        for(int i=0;i<len;i++){  
            tank += diff[i];  
            sum += diff[i];  
            if(sum<0){//意味着走不下去了，要重新选起点  
                sum = 0;  
                startnode = i+1;  
            }  
        }  
        if(tank<0)  
            return -1;  
        else   
            return startnode;  
    }
};