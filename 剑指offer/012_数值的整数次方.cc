//给定一个double类型的浮点数base和int类型的整数exponent。
//求base的exponent次方。

class Solution {
public:
    double Power(double base, int exponent) {
    	if(exponent==0)
            return 1;
        if(exponent<0)
            return 1/Power(base,-1*exponent);
        double result=base;
        int count=exponent;
        while(count>1){
            count/=2;
            result*=result;
        }
        if((exponent&1)==1)
            result*=base;
        return result;
    }
};