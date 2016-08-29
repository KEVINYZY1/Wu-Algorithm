#include<cmath>
//使用类似于回文字符串的判断方法，对整数进行首尾判断，而不是将整数逆序再比较是否相等，因为这样会出现overflow
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int base=0;
        int y=x;
        while(y){
            base++;
            y/=10;
        }
        for(int i=0;i<base/2;++i){
            int left=x/pow(10,base-1-i);
            left%=10;
            int temp=pow(10,i);
            int right=(x/temp)%10;
            if(right!=left)
                return false;
        }
        return true;
    }
};