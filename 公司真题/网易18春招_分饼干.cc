/*
分饼干
时间限制：1秒
空间限制：32768K
易老师购买了一盒饼干，盒子中一共有k块饼干，但是数字k有些数位变得模糊了，看不清楚数字具体是多少了。易老师需要你帮忙把这k块饼干平分给n个小朋友，易老师保证这盒饼干能平分给n个小朋友。现在你需要计算出k有多少种可能的数值 
输入描述:
输入包括两行：

第一行为盒子上的数值k，模糊的数位用X表示，长度小于18(可能有多个模糊的数位)

第二行为小朋友的人数n


输出描述:
输出k可能的数值种数，保证至少为1

输入例子:
9999999999999X
3

输出例子:
4
*/

/* 超时，要用动态规划，另外long long 范围不到18位
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void findNumsK(string k, int n, int index, int &res){
    for(int i = index; i < k.size(); i++){
        if(k[i] == 'X'){
            for(int j = 0; j < 10; j++){
                if(i == 0 && j==0){
                    continue;
                }
                else{
                    k[i] = '0' + j;
                }
                findNumsK(k, n, i + 1, res);
            }
            return;
        }
    }
    //遍历完字符串k，补充了所有的模糊数位
    stringstream ss;
    ss << k;
    long long num;
    ss >> num;
    if(num % n == 0)
        res++;
}

//考虑模糊位在开头不能为0
//回溯，依次试验
int main(){
    string k;
    int n;
    cin >> k >> n;
    int res = 0;
    findNumsK(k, n, 0, res);
    cout << res << endl;
}
*/

#include<iostream>
#include<vector>
using namespace std;
#define MAXN 100000

//dp，mod[k]表示当前所有情况下模n余k的数量
void transform1(vector<long long> &mod, int n){
    vector<long long> tmpMod(MAXN);
    for(int i = 0;i < n; i++){
        for(int j = 0; j < 10; j++){
            tmpMod[(i*10+j)%n] += mod[i];
        }
    }
    swap(tmpMod, mod);
}
void transform2(vector<long long> &mod,int k,int n){
    vector<long long> tmpMod(MAXN);
    for(int i = 0; i < n; i++){
        tmpMod[(i*10+k)%n] += mod[i];
    }
    swap(tmpMod, mod);
}
int main(){
    vector<long long> mod(MAXN);
    string s;
    int n;
    cin >> s >> n;
    mod[0] = 1;
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='X'){
            transform1(mod, n);
        }else{
            transform2(mod, s[i]-'0',n);
        }
    }
    cout << mod[0] << endl;
}