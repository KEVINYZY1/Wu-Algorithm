/*
暗黑的字符串
一个只包含'A'、'B'和'C'的字符串，如果存在某一段长度为3的连续子串中恰好'A'、'B'和'C'各有一个，那么这个字符串就是纯净的，否则这个字符串就是暗黑的。例如：
BAACAACCBAAA 连续子串"CBA"中包含了'A','B','C'各一个，所以是纯净的字符串
AABBCCAABB 不存在一个长度为3的连续子串包含'A','B','C',所以是暗黑的字符串
你的任务就是计算出长度为n的字符串(只包含'A'、'B'和'C')，有多少个是暗黑的字符串。 
输入描述:
输入一个整数n，表示字符串长度(1 ≤ n ≤ 30)


输出描述:
输出一个整数表示有多少个暗黑字符串

输入例子:
2
3

输出例子:
9
21
*/

#include<iostream>
using namespace std;
//主要是推导公式：
//例如：在字符串BAA的后面只能有两种添加字符的方法                   f(n-1)=s(n-1)+d(n-1)
//1.添加和末尾相同的字符变成BAAA，一定不是暗黑的字符串               3*s(n-1)
//2.添加和末尾不同的字符串变成BAAB或BAAC，一定不是暗黑字符串         2*d(n-1)
//用dp[0]和dp[1]分别表示上一次的添加方式对应的暗黑字符串的个数        f(n)=3*s(n-1)+2*d(n-1)=2f(n-1)+s(n-1)
//所以公式为：dp[0] = temp0 + temp1; dp[1] = 2*temp0 + temp1;   s(n)=s(n-1)+d(n-1)  d(n)=2*s(n-1)+d(n-1)
long long blackNum(int n){
    if(n == 1)return 3;
    if(n == 2)return 9;
    long long dp[2];
    dp[0] = 3;
    dp[1] = 6;
    for(int i = 2;i<n;i++){
        long long temp0 = dp[0];
        long long temp1 = dp[1];
        dp[0] = temp0 + temp1;
        dp[1] = 2*temp0 + temp1;
    }
    return dp[0]+dp[1];
}
int main(){
    int n;
    while(cin>>n){
        cout<<blackNum(n)<<endl;
    }
    return 0;
}