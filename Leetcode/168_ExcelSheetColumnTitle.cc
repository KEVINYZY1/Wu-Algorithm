#include<string>
using namespace std;

//类似于进制之间的转换
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        if(n<=0)
            return result;
        
        while(n!=0){//每次都要n-1
            result = (char)((n-1)%26+'A') + result;//从高位向低位算
            n = (n-1)/26;
        }
        return result;
    }
};