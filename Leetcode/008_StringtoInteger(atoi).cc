#include<string>
#include<limits.h>
using namespace std;
//正负号同时存在的，返回0，另外加号或者减号必须和数字连续的出现
//开头出现空格直接无视
//存在非数字的字符则直接返回0
//若是存在overflow情况，则返回INT_MAX或者INT_MIN
class Solution {
public:
    int myAtoi(string str) {
        if (str == "") 
            return 0;
        // 去首尾空格，利用stl
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);
        int overflowFlag = 0;
        int i = 0, len = str.length(), sign = 1;

        while (i < len && str[i] == ' ') 
            i++;
        if (i == len) 
            return 0;
        if (str[i] == '+') {
            sign = 1;
            i++;
        } else if (str[i] == '-') {
            sign = -1;
            i++;
        }
        int result = 0;
        for (; i < len; i++) {
            if (str[i] < '0' || str[i] > '9') 
                break;
            int nextResult = result * 10 + (str[i] - '0');
            if ((nextResult/10)!=result){
                overflowFlag=1;
                break;
            }
            result = nextResult;
        }
        if (overflowFlag)
            return (sign == 1) ? INT_MAX : INT_MIN;
        return result * sign;
    }
};