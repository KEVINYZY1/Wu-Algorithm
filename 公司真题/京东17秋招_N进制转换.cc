/*
进制转换
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数 
输入描述:
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。


输出描述:
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）

输入例子:
7 2

输出例子:
111
*/

#include <iostream>
using namespace std;

int main(){
    int M,N;
    cin>>M>>N;
    if(N==10){
        cout<<M<<endl;
        return 0;
    }
    //小心负数
    bool fuck=false;
    if(M<0){
        M*=-1;
        fuck=true;
    }
    
    //从十进制转换成N进制
    string res;
    while(M){
        int temp=M%N;
        if(temp>9){//10进制以上的话
            res=static_cast<char>('A'+temp-10)+res;
        }
        else{
            res=static_cast<char>('0'+temp)+res;
        }
        M/=N;
    }
    if(fuck)
        res='-'+res;
    cout<<res<<endl;
}