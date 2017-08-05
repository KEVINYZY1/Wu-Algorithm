/*
计算最少出列多少位同学，使得剩下的同学排成合唱队形
说明：
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。 
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，   则他们的身高满足存在i（1<=i<=K）使得T1<T2<......<Ti-1<Ti>Ti+1>......>TK。 
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。 



输入描述:
整数N


输出描述:
最少需要几位同学出列
示例1
输入

8
186 186 150 200 160 130 197 200
输出

4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//开始没思路，后来就看了别人的解法
//两遍最长严格递增子序列，第一遍从左往右，第二遍从右往左，然后把两遍动态规划的结果相加
//取最大的那个，比如8 186 186 150 200 160 130 197 200，第一遍dp的结果是 1 1 1 2 2 1 3 4，
//第二遍dp的结果为3 3 2 3 2 1 1 1，那么相加最大是5，所以需要出列的同学个数就是8-5+1=4

int main() {
    int N;
    while (cin >> N) {
        vector<int> v(N);
        for (auto &item : v) {
            cin >> item;
        }
        vector<int> dpLeft(N, 1);
        vector<int> dpRight(N, 1);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (v[i] > v[j])
                    dpLeft[i] = max(dpLeft[i], dpLeft[j] + 1);
            }
        }
        reverse(v.begin(), v.end());
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (v[i] > v[j])
                    dpRight[i] = max(dpRight[i], dpRight[j] + 1);
            }
        }
        reverse(dpRight.begin(), dpRight.end());//理解题意-0-
        int max = 0;
        for (int i = 0; i < N; i++) {
            if (max < dpLeft[i] + dpRight[i])
                max = dpLeft[i] + dpRight[i];
        }
        cout << N - max + 1 << endl;
    }
}