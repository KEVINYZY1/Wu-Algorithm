#include<string>
using namespace std;

//9!在int范围内
//可以用permutation k-1次，但是超时
//使用康托编码
//把阶乘函数独立出来。
class Solution {
public:
    string getPermutation(int n, int k) {//获取第k个排列！！！
        string result(n,'0');
        //生成字符串1到n
        for(int i=0;i<n;++i){
            result[i]+=i+1;
        }
        if(k>factorial(n))
            return result;
        return kthPermutation(result,k);
    }
private:
    int factorial(int n){
        int product=1;
        while(n>1){
            product*=n;
            --n;
        }
        return product;
    }
    string kthPermutation(string s,int k){
        int factor=factorial(s.size()-1);
        int n=s.size()-1;
        --k;//因为string从0开始
        string result;
        int reminder=k/factor;
        for(;n>=1;--n){
            auto a=next(s.begin(),reminder);
            result.push_back(*a);
            s.erase(a);
            k%=factor;
            factor/=n;
            reminder=k/factor;
        }
        result+=s;
        return result;
    }
};