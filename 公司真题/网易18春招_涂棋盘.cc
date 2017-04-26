/*
涂棋盘
时间限制：1秒
空间限制：32768K
小易有一块n*n的棋盘，棋盘的每一个格子都为黑色或者白色，小易现在要用他喜欢的红色去涂画棋盘。小易会找出棋盘中某一列中拥有相同颜色的最大的区域去涂画，帮助小易算算他会涂画多少个棋格。 
输入描述:
输入数据包括n+1行：

第一行为一个整数n(1 ≤ n ≤ 50),即棋盘的大小

接下来的n行每行一个字符串表示第i行棋盘的颜色，'W'表示白色，'B'表示黑色


输出描述:
输出小易会涂画的区域大小

输入例子:
3
BWW
BBB
BWB

输出例子:
3
*/

#include <iostream>
#include <vector>
using namespace std;

int findMaxArea(vector<char> &nums){
    int res = 0;
    if(nums.empty())
        return res;
    char prev = nums[0];
    int count = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == prev){
            count++;
        }
        else{
            res = max(res, count);
            count = 1;
            prev = nums[i];
        }
    }
    res = max(res, count);//最后需要也比较一下
    return res;
}
int main(){
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[j][i];//转置
        }
    }
    int res = 0;
    for(auto &each : v){
        res = max(findMaxArea(each), res);
    }
    cout << res << endl;
}