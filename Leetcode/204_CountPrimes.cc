#include<vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;
        int count=0;
        vector<bool>b(n,true);
        b[0]=false;
        for(int i=2;i*i<n;i++){//sqrt(n);i++){
            if(b[i-1]==false)//剪枝
                continue;
            for(int j=2;i*j<=n;j++){
                b[i*j-1]=false;
            }
        }
        for(int i=0;i<n-1;i++)
            if(b[i]==true)
                count++;
        return count;
    }
};