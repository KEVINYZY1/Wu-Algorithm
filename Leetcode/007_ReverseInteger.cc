#include<string>
#include<vector>
using namespace std;
//大数问题，主要防止越界和0
//方法一，防止越界，主要利用乘10和除10之后，数值是否会发生变化。并不需要特殊考虑负数问题
class Solution {
public:
    int reverse(int x) {
        if (x == 0 || x == INT_MIN)
            return 0;
        if (x < 0)
            return -1 * reverse(-x);
        int res = 0;
        while (x) {
            int last = x % 10;
            x /= 10;
            int storeRes = res;
            res *= 10;
            res += last;
            if ((res - last) / 10 != storeRes)
                return 0;
        }
        return res;
    }
};
//方法二，可以用long类型或者字符串来保存反转的数，最后判断是否越界
class Solution2 {
public:
    int reverse(int x) {
        int sign=1;
        long result=0;
        while(x){
            result*=10;
            result=result+x%10;
            x/=10;
            if(result>INT_MAX||result<INT_MIN)return 0;
        }
        return result;
    }
};