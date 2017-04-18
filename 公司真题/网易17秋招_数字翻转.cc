/*
对于一个整数X，定义操作rev(X)为将X按数位翻转过来，并且去除掉前导0。例如:
如果 X = 123，则rev(X) = 321;
如果 X = 100，则rev(X) = 1.
现在给出整数x和y,要求rev(rev(x) + rev(y))为多少？ 
输入描述:
输入为一行，x、y(1 ≤ x、y ≤ 1000)，以空格隔开。


输出描述:
输出rev(rev(x) + rev(y))的值

输入例子:
123 100

输出例子:
223
*/

#include <iostream>
using namespace std;

//考虑前面有0情况，还有考虑负数情况
int rev(int num){
    int res=0;
    bool fuck=num>0? true : false;
    if(!fuck)
        num*=-1;
    while(num!=0){
        int temp=num%10;
        res*=10;
        res+=temp;
        num/=10;
    }
    return res;
}

int main(){
	int x, y;
    cin>>x>>y;
    int res=rev(rev(x)+ rev(y));
    cout<<res<<endl;
}