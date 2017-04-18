/*
给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。 
输入描述:
输入为两行:

第一行为两个正整数n(1 ≤ n ≤ 1000)，sum(1 ≤ sum ≤ 1000)

第二行为n个正整数A[i](32位整数)，以空格隔开。


输出描述:
输出所求的方案数

输入例子:
5 15
5 5 10 2 3

输出例子:
4
*/
/* dfs会超时！！！
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> &v, int index, int tempSum, int sum, int &count){
    if(tempSum > sum)
        return;
    if(tempSum == sum){
        count++;
        return;
    }
    for(int i = index + 1; i < v.size(); i++){
        dfs(v, i, tempSum + v[i], sum, count);
    }
}

int main(){
    int n, sum;
    while(cin >> n >> sum){
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int count = 0;
        for(int i = 0; i < n; i++){
            if(v[i] <= sum)
            	dfs(v, i, v[i], sum, count);
        }
        cout << count << endl;
    }
}
*/
/*
动态规划
dp[]数组，下标为背包总重，值为到背包总重的方法
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bag(vector<int> &v, int sum){
    vector<int> b(sum+1, 0);
    b[0] = 1;//背包重量为0，不管啥时候都有一种办法
    for(int i = 0; i < v.size(); i++){
        for(int j = sum; j > v[i]; j--){
            b[j] = b[j] + b[j - v[i]];
        }
    }
    cout << b[sum] << endl;
}

int main(){
    int n, sum;
    while(cin >> n >> sum){
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        bag(v, sum);
    }
}
