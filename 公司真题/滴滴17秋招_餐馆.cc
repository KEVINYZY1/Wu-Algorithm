/*
某餐馆有n张桌子，每张桌子有一个参数：a 可容纳的最大人数； 有m批客人，每批客人有两个参数:b人数，c预计消费金额。 在不允许拼桌的情况下，请实现一个算法选择其中一部分客人，使得总预计消费金额最大 
输入描述:
输入包括m+2行。
第一行两个整数n(1 <= n <= 50000),m(1 <= m <= 50000)
第二行为n个参数a,即每个桌子可容纳的最大人数,以空格分隔,范围均在32位int范围内。
接下来m行，每行两个参数b,c。分别表示第i批客人的人数和预计消费金额,以空格分隔,范围均在32位int范围内。


输出描述:
输出一个整数,表示最大的总预计消费金额

输入例子:
3 5
2 4 2
1 3
3 5
3 7
5 9
1 10

输出例子:
20
*/

#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//思路：把餐桌椅子个数从小到大排，把顾客数从小到大排，然后从第一个餐桌开始，能放进去的顾客数中找到消费量最大的塞进餐桌
//或者说，我是把餐桌椅子个数从小到大排，把顾客的金额从小到大排，先满足最大金额的，保证最大金额的使用的椅子数桌子是最少的，然后依次走下去。
int main(){
	int n, m;
	vector<int> a;
	for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<pair<int, int> > v;
    for(int i=0; i<m; i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(a.begin(), a.end());
    list<int> l(a.begin(), a.end());
    sort(v.begin(), v.end(),[](pair<int,int> x, pair<int, int> y){
        return x.second>y.second;
    });
    
    int count=0;
    for(int i=0; i<m; i++){
        //从最小的容量桌子开始
        for(auto it=l.begin(); it!=l.end(); it++){
            if(*it>v[i].first){
                l.erase(it);
                count+=v[i].second;
                break;
            }
        }
    }
    cout<<count<<endl;
}