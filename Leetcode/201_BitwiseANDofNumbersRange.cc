//[m, n]范围内，所有数都&操作，然后得返回最后结果。
//最后返回的数是该数字范围内所有的数的二进制左边共同的部分
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        while(m!=n){
            m>>=1;
            n>>=1;
            i++;
        }
        m<<=i;
        return m;
    }
};