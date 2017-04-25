/*
消除重复元素
时间限制：1秒
空间限制：32768K
小易有一个长度为n序列，小易想移除掉里面的重复元素，但是小易想是对于每种元素保留最后出现的那个。小易遇到了困难,希望你来帮助他。 
输入描述:
输入包括两行：
第一行为序列长度n(1 ≤ n ≤ 50)
第二行为n个数sequence[i](1 ≤ sequence[i] ≤ 1000)，以空格分隔


输出描述:
输出消除重复元素之后的序列，以空格分隔，行末无空格

输入例子:
9
100 100 100 99 99 99 100 100 100

输出例子:
99 100
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> m;//记录相同元素最后一次出现的下标
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        m[temp] = i;
    }
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](pair<int, int> l, pair<int, int> r){
        return l.second <r.second;
    });
    for(int i = 0; i < v.size(); i++){
        if(i == v.size() - 1)
            cout << v[i].first <<endl;
        else cout << v[i].first << ' ';
    }
}