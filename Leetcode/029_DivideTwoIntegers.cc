#include<vector>
#include <complex>
using namespace std;

//位运算实现整数除法
//要考虑正负很烦人
//之前考虑的是对被除数一直右移缩小，得不出结果，应该对除数左移放大到接近被除数的时候，再用减法求结果。
//这里为了防止大数溢出，只能用long了吗？？？
class Solution {
public:
    int divide(int dividend, int divisor) {
        if ((dividend == INT_MIN && divisor == -1) || divisor == 0) 
            return INT_MAX;//溢出情况
        int sign = (dividend < 0 ^ divisor < 0) ? - 1 : 1;
        long tempDividend = abs((long)dividend), tempDivisor = abs((long)divisor);//注意得先转换long，不然INT_MIN变正会溢出
        if (tempDividend < tempDivisor) 
            return 0;
        int h = 0;
        long t = tempDivisor;
        while (t <= tempDividend) 
            t <<= 1, h++;
        long result = 1 << --h;
        tempDividend -= (t >>= 1);
        while (tempDividend >= tempDivisor) {//关键，保证每次减去最接近tempDividend的除数倍数
            while (t > tempDividend)
                t >>= 1, h--;
            result |= 1 << h;
            tempDividend -= t;
        }
        return result * sign;
    }
};