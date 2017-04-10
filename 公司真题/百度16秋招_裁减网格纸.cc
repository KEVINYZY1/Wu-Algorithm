/*
度度熊有一张网格纸，但是纸上有一些点过的点，每个点都在网格点上，若把网格看成一个坐标轴平行于网格线的坐标系的话，每个点可以用一对整数x，y来表示。度度熊必须沿着网格线画一个正方形，使所有点在正方形的内部或者边界。然后把这个正方形剪下来。问剪掉正方形的最小面积是多少。 
输入描述:
第一行一个数n(2≤n≤1000)表示点数，接下来每行一对整数xi,yi(－1e9<=xi,yi<=1e9)表示网格上的点


输出描述:
一行输出最小面积

输入例子:
2
0 0
0 3

输出例子:
9
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//最大差
int findMaxDiff(vector<int> &nums){
    const int len=nums.size();
    if(len<2){
        return 0;
    }
    int maxNum=nums[0]>nums[1]?nums[0]:nums[1];
    int minNum=nums[0]>nums[1]?nums[1]:nums[0];
    for(int i=2; i<len; i++){
        if(nums[i]>maxNum){
            maxNum=nums[i];
        }
        else if(nums[i]<maxNum){
            minNum=min(nums[i], minNum);
        }
    }
    return maxNum-minNum;
}
 
int main(){
    //寻找x和y数组中最大差？
    int n;
    while(cin>>n){
        vector<int> x(n);
        vector<int> y(n);
        for(int i=0; i<n; i++){
            cin>>x[i]>>y[i];
        }
        int edge = max(findMaxDiff(x), findMaxDiff(y));
        cout<<edge*edge<<endl;/*唯一需要注意的是pow函数输出的double，题目需要的是int，务必小心*/
    }
}