/*
买苹果
小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个每袋的包装(包装不可拆分)。 可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。如果不能购买恰好n个苹果，小易将不会购买。 
输入描述:
输入一个整数n，表示小易想购买n(1 ≤ n ≤ 100)个苹果


输出描述:
输出一个整数表示最少需要购买的袋数，如果不能买恰好n个苹果则输出-1

输入例子:
20

输出例子:
3
*/

#include <iostream>
using namespace std;

int main(){
	int n;
    cin>>n;
    if((n&1)==1){
        cout<<-1<<endl;
        return 0;
    }
    int res=0;
    int temp=n/8;
    temp*=8;
    if(temp<n){
        temp+=8;
    }
    res+=temp/8;
    int diff=temp-n;
    int count=0;
    while(diff){//这里可以优化下
        diff-=2;
        count++;
    }
    if(count>res){
        cout<<-1<<endl;
    }
    else cout<<res<<endl;
}