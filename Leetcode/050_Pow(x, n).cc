#include<limits.h>


//要分别考虑n为正数和负数的情况，n为负数时，要考虑n为INT_MIN的情况
//对n采用了二分法，注意要避免二分不到位。
//时间复杂度O(lgn)
class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            if(n==INT_MIN)
                return 1.0/(x*myPow(x,INT_MAX));
            return 1.0/myPow(x,-n);
        }
        if(n==0)
            return 1.0;
        double half = myPow(x,n>>1);  
        if(n%2==0)  
            return half*half;  
        else  
            return half*half*x;  
    }
};