//将32位无符号整数的比特位逆序
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        for(int i=0;i<32;i++){
            if(n&1==1)
                 result=(result<<1)+1;
            else result<<=1;
            n>>=1;
        }
        return result;
    }
};