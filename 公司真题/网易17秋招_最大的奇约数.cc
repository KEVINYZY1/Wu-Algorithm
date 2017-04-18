/*
最大的奇约数
小易是一个数论爱好者，并且对于一个数的奇数约数十分感兴趣。一天小易遇到这样一个问题： 定义函数f(x)为x最大的奇数约数，x为正整数。 例如:f(44) = 11.
现在给出一个N，需要求出 f(1) + f(2) + f(3).......f(N)
例如： N = 7 
f(1) + f(2) + f(3) + f(4) + f(5) + f(6) + f(7) = 1 + 1 + 3 + 1 + 5 + 3 + 7 = 21
小易计算这个问题遇到了困难，需要你来设计一个算法帮助他。 
输入描述:
输入一个整数N (1 ≤ N ≤ 1000000000)


输出描述:
输出一个整数，即为f(1) + f(2) + f(3).......f(N)

输入例子:
7

输出例子:
21
*/

/*耗时方法！ 一个一个算。虽然作了优化，比如奇数不算，偶数也是快速找到
#include <iostream>
using namespace std;

int getMaxOdd(int num){
    int res=0;
    if((num&1)==1){
        return num;
    }
    else{
        int start=num/2;
        if((start&1)==1)
            return start;
        for(int i=start-1; i>=1; i-=2){
            if(num%i==0)
                return i;
        }
    }
    return num;
}

int main(){
	int n;
    cin>>n;
    int res=0;
    for(int i=1; i<=n; i++){
        res+=getMaxOdd(i);
    }
    cout<<res<<endl;
}
*/

//在奇数不用计算的基础上，实现递归
//还需要注意一点，大数溢出，要用long类型
#include <iostream>
using namespace std;

long getSum(long num){
    if(num==1)
        return 1;
    long res=0;
    if((num&1) == 1){
        res+=(num+1)*(num+1)/4;
    }
    else{
        res+=num*num/4;
    }
    return res+getSum(num/2);
}

int main(){
	int n;
    cin>>n;
    long res=0;
 	res=getSum(n);
    cout<<res<<endl;
}