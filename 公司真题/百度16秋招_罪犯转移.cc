/*
C市现在要转移一批罪犯到D市，C市有n名罪犯，按照入狱时间有顺序，另外每个罪犯有一个罪行值，值越大罪越重。现在为了方便管理，市长决定转移入狱时间连续的c名犯人，同时要求转移犯人的罪行值之和不超过t，问有多少种选择的方式？ 

输入描述:
第一行数据三个整数:n，t，c(1≤n≤2e5,0≤t≤1e9,1≤c≤n)，第二行按入狱时间给出每个犯人的罪行值ai(0≤ai≤1e9)


输出描述:
一行输出答案。

输入例子:
3 100 2
1 2 3

输出例子:
2
*/

#include<iostream>
#include<vector>
using namespace std;
 
//没有通过的理由，居然是自己要循环所有测试用例，无语
int main(){
    int n, t, c;
    while(cin>>n>>t>>c){
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int count = 0;
        int all = 0;
        //默认c小于n
        if(c > n){
            cout<<0<<endl;
            return 0;
        }
            
        for(int i = 0; i < c; i++){
            all += a[i];
        }
        if(all <= t)
            count++;
        for(int i = c; i < n; i++){
            all -= a[i-c];
            all += a[i];
            if(all <= t)
                count++;
        }
        cout<<count<<endl;
    }
}