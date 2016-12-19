/*
我们从低位到高位求每位1出现的次数，累加求和即可
例如：求0~abcde中1的个数，现在我们求c这一位中1出现的次数，其他位雷同
有两部分组成
第一部分：
ab * 100，表示当ab这两位在0~ab-1范围内时，de可以从0~99取值
第二部分：
如果c>1时，当ab为ab时1的个数为0~99
如果c=1时，当ab为ab时1的个数为de + 1
如果c<0时，当ab为ab是1的个数为0
*/
class Solution {
public:
    int countDigitOne(int n) {
        if(n<1)
            return 0;
        long long exp = 1;//小心溢出
        long long ans = 0; 
        while(n / exp){
            ans += n / (exp * 10) * exp;
            if(n % (exp * 10) / exp  > 1) 
                ans += exp;
            else if(n % (exp * 10) / exp == 1) 
                ans += (n % exp + 1);
            exp *= 10;
        }
        return ans;
    }
};