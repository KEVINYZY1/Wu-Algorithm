/*
连续最大和
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3 
输入描述:
输入为两行。
第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素
第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。


输出描述:
所有连续子数组中和最大的值。

输入例子:
3
-1 2 1

输出例子:
3
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    //dp
    vector<int> dp(n);
    int maxCount=0;
    dp[0]=v[0]>0 ? v[0] : 0;
    for(int i=1; i<n; i++){
        if(dp[i-1] + v[i] > dp[i-1]){
            dp[i] = dp[i-1] + v[i];
        }
        else if(dp[i-1] + v[i] > 0) {
            dp[i] = dp[i-1] + v[i];
        }
        else dp[i] = 0;
    }
    
    //遍历
    for(int i=0; i<n; i++){
        maxCount=max(maxCount, dp[i]);
    }
    //一开始没有考虑到全是负数的情况。
    if(maxCount==0){
        maxCount=v[0];
    	for(int i=1; i<n; i++){
			maxCount=max(maxCount, v[i]);
        }
    }
    cout<<maxCount<<endl;
}
