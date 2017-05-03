/*
寻找三角形
时间限制：1秒
空间限制：32768K
三维空间中有N个点，每个点可能是三种颜色的其中之一，三种颜色分别是红绿蓝，分别用'R', 'G', 'B'表示。 
现在要找出三个点，并组成一个三角形，使得这个三角形的面积最大。
但是三角形必须满足：三个点的颜色要么全部相同，要么全部不同。 
输入描述:
首先输入一个正整数N三维坐标系内的点的个数.(N <= 50) 

接下来N行，每一行输入 c x y z，c为'R', 'G', 'B' 的其中一个。x，y，z是该点的坐标。(坐标均是0到999之间的整数)


输出描述:
输出一个数表示最大的三角形面积，保留5位小数。

输入例子:
5
R 0 0 0
R 0 4 0
R 0 0 3
G 92 14 7
G 12 16 8

输出例子:
6.00000
*/
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
 
using namespace std;
 
struct Points { //定义结构体Points
    char c;
    int x, y, z;
};
 
//通过三条边计算三角形面积，海伦公式
double CountTriangleArea(Points A, Points B, Points C) { //根据三个点计算三角形面积
    double a = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2) + pow(A.z - B.z, 2));
    double b = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2) + pow(A.z - C.z, 2));
    double c = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2) + pow(C.z - B.z, 2)); //计算三边长度a, b, c
    if (a + b <= c || a + c <= b || b + c <= a) //排除掉不符合的情形
        return -1;
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
//判断三点是否一条直线
//通过三条边计算三角形面积 
int main() {
    int N;
    Points p[N];
    double MaxArea = 0;
    for (int i = 0; i < N; cin >> p[i++].c >> p[i - 1].x >> p[i - 1].y >> p[i - 1].z);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i != j)
                for (int k = 0; k < N; ++k)
                    if (k != i && k != j && ((p[i].c != p[j].c && p[i].c != p[k].c
                                              && p[j].c != p[k].c) || (p[i].c == p[j].c && p[i].c == p[k].c)))
                        if (CountTriangleArea(p[i], p[j], p[k]) > MaxArea)
                            MaxArea = CountTriangleArea(p[i], p[j], p[k]);
    printf("%.5f", MaxArea);
}