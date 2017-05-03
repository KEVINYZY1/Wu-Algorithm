/*
有趣的排序
时间限制：1秒
空间限制：32768K
度度熊有一个N个数的数组，他想将数组从大到小排好序，但是萌萌的度度熊只会下面这个操作：
任取数组中的一个数然后将它放置在数组的最后一个位置。
问最少操作多少次可以使得数组从小到大有序？ 
输入描述:
首先输入一个正整数N，接下来的一行输入N个整数。(N <= 50, 每个数的绝对值小于等于1000)


输出描述:
输出一个整数表示最少的操作次数。

输入例子:
4
19 7 8 25

输出例子:
2
*/

/*
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main(){
    int N;
    cin >> N;
    list<int> nums;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int count = 0;
    while(1){
        int temp = *(--nums.end());
        bool fuck = true;
        for(auto it = nums.rbegin(); it != nums.rend(); it++){
            if(*it > temp){
                nums.push_back(*it);
                nums.erase(it.base());//erase不能删除逆迭代器，用base转换
                count++;
                fuck = false;
                break;
            }
        }
        if(fuck)
            break;
    }
    cout << count << endl;
}*/

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n,temp;
    cin>>n;
    vector<int> v;
    map<int,int> m;
    for(int i=0;i<n;i++) {  
        cin>>temp;
        v.push_back(temp);
        m[temp]=i;
    }
    sort(v.begin(),v.end());
    int t=n,count=0;
    for(int i=0;i<n-1;i++) {
        if (m[v[i]]>m[v[i+1]]){
            m[v[i+1]]=t++;//记住更新下标
            count++;
        }
    }
    cout<<count<<endl;
}
