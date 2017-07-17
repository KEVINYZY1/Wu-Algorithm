//求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
//为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
//ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n){
    	if(n<1)
            return 0;
        long long exp = 1;//小心溢出
        long long ans = 0; 
        while(n/exp){
            ans += n/(exp * 10) * exp;//个位数的1
            //剩下开始判断，
            if(n % (exp * 10) / exp  > 1) 
                ans += exp;
            else if(n % (exp * 10) / exp == 1) 
                ans += (n % exp + 1);
            exp *= 10;
        }
        return ans;
    }
};

//衍生题   如果是其他数字呢

//当计算0出现的次数时候
