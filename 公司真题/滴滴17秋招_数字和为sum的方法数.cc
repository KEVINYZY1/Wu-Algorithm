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

//dp来做！