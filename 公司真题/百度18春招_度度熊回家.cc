/*
度度熊回家
时间限制：1秒
空间限制：32768K
一个数轴上共有N个点，第一个点的坐标是度度熊现在位置，第N-1个点是度度熊的家。现在他需要依次的从0号坐标走到N-1号坐标。
但是除了0号坐标和N-1号坐标，他可以在其余的N-2个坐标中选出一个点，并直接将这个点忽略掉，问度度熊回家至少走多少距离？ 
输入描述:
输入一个正整数N, N <= 50。

接下来N个整数表示坐标，正数表示X轴的正方向，负数表示X轴的负方向。绝对值小于等于100


输出描述:
输出一个整数表示度度熊最少需要走的距离。

输入例子:
4
1 4 -1 3

输出例子:
4
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> postions(N);
    for(int i = 0; i < N; i++){
        cin >> postions[i];
    }
    int costAll = 0;
    vector<int> postionCost(N, 0);
    for(int i = 1; i < N; i++){
        postionCost[i] = abs(postions[i] - postions[i-1]);
        costAll += postionCost[i];
    }
    vector<int> delCost(N, 0);
    for(int i = 1; i < N - 1; i++){
        int cost = postionCost[i] + postionCost[i+1];
        delCost[i] = cost - abs(postions[i+1] - postions[i-1]);
    }
    int res = costAll;
    int mostCost = 0;
    for(int i = 1; i < N - 1; i++){
        mostCost = max(mostCost, delCost[i]);
    }
    cout << (res - mostCost);
}