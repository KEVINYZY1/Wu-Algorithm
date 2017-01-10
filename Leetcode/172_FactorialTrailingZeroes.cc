//计算n!结果末尾0的个数
//那么就是计算n!含5因子的个数
class Solution {
public:
    int trailingZeroes(int n) {
        int result=0;
        while(n>0){
            result+=n/5;
            n/=5;
        }
        return result;
    }
};