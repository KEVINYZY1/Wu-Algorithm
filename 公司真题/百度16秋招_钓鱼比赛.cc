/*
ss请cc来家里钓鱼，鱼塘可划分为n＊m的格子，每个格子有不同的概率钓上鱼，cc一直在坐标(x,y)的格子钓鱼，而ss每分钟随机钓一个格子。问t分钟后他们谁至少钓到一条鱼的概率大？为多少？

输入描述:
第一行五个整数n,m,x,y,t(1≤n,m,t≤1000,1≤x≤n,1≤y≤m);
接下来为一个n＊m的矩阵，每行m个一位小数，共n行，第i行第j个数代表坐标为(i,j)的格子钓到鱼的概率为p(0≤p≤1)


输出描述:
输出两行。第一行为概率大的人的名字(cc/ss/equal),第二行为这个概率(保留2位小数)

输入例子:
2 2 1 1 1
0.2 0.1
0.1 0.4

输出例子:
equal
0.20
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;
 
int main(){
    int n, m, x, y, t;
    while(cin>>n>>m>>x>>y>>t){
        vector<vector<double>> v(n, vector<double>(m));
        double all=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>v[i][j];
                all+=v[i][j];
            }
        }
        double per=all/m/n;
        double proC=0, proS=0;
        //至少钓到一条鱼，概率论。
        proC=1-pow((1-v[x-1][y-1]),t);//x,y要分别减一
        proS=1-pow((1-per),t);
        //如何保留double两位
        if(proC>proS){
            cout<<"cc"<<endl;
            printf("%.2f\n",proC);/* 注意！ 使用printf，要记得加\n换行*/
        }
        else if(proC<proS){
            cout<<"ss"<<endl;
            printf("%.2f\n",proS);
        }
        else{
            cout<<"equal"<<endl;
            printf("%.2f\n",proS);
        }
    }
}