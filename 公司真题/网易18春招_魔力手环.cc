/*
魔力手环
时间限制：1秒
空间限制：32768K
小易拥有一个拥有魔力的手环上面有n个数字(构成一个环),当这个魔力手环每次使用魔力的时候就会发生一种奇特的变化：每个数字会变成自己跟后面一个数字的和(最后一个数字的后面一个数字是第一个),一旦某个位置的数字大于等于100就马上对100取模(比如某个位置变为103,就会自动变为3).现在给出这个魔力手环的构成，请你计算出使用k次魔力之后魔力手环的状态。 
输入描述:
输入数据包括两行：
第一行为两个整数n(2 ≤ n ≤ 50)和k(1 ≤ k ≤ 2000000000),以空格分隔
第二行为魔力手环初始的n个数，以空格分隔。范围都在0至99.


输出描述:
输出魔力手环使用k次之后的状态，以空格分隔，行末无空格。

输入例子:
3 2
1 2 3

输出例子:
8 9 7
*/

/* 普通模拟，超时，时间复杂度O(kn)
#include <iostream>
#include <vector>
using namespace std;

//从后往前
void MagicChange(vector<int> &nums){
    if(nums.empty())
        return;
    const int len = nums.size();
    int store = nums[len - 1];
    nums[len - 1] += nums[0];
    if(nums[len - 1] >= 100)
        nums[len - 1] %= 100;
    for(int i = len - 1; i >= 0; i--){
        if(i == len - 1)
            continue;
        int temp = nums[i];
        nums[i] += store;
        if(nums[i] >= 100)//不影响其他数字计算
            nums[i] %= 100;
        store = temp;
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    while(k--)
        MagicChange(v);
    for(int i = 0; i < n; i++){
        if(i == n - 1)
            cout << v[i] << endl;
        else cout << v[i] << ' ';
    }
}
*/
/*
时间复杂度O(nlogk)
如输入A = [[1, 2, 3]], k = 2。
我们可以构造一个这样的矩阵B（代码中的mul矩阵）[[1, 0, 1], [1, 1, 0], [0, 1, 1]]，使得A*Bk相当于A转换k次后的样子。
于是原问题就变成求矩阵快速幂。快速幂取余中，a k % c =  (a % c)k % c。
*/
#include <iostream>
#include <vector>
using namespace std;
 
class Matrix {
public:
    int n, m;
    vector<vector<int>> mat;
    Matrix(vector<int>& vec) {
        n = 1;
        m = vec.size();
        mat.emplace_back(vec);
    }
 
    Matrix(int n, int m) : n(n), m(m) {
        mat.resize(n, vector<int>(m, 0));
    }
 
    Matrix(int n = 0) : n(n), m(n) {
        //构造矩阵B
        mat.resize(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            mat[i][i] = 1;
            if (i + 1 < n)
                mat[i+1][i] = 1;
            else
                mat[0][i] = 1;
        }
    }
 
    Matrix& operator * (Matrix& b) {
        Matrix temp(this->n, b.m);
        if (this->m == b.n) {
            for (int i = 0; i < temp.n; ++i) {
                for (int j = 0; j < temp.m; ++j) {
                    for (int k = 0; k < m; ++k) {
                        temp.mat[i][j] += this->mat[i][k] * b.mat[k][j];
                    }
                }
            }
        }
        *this = temp;
        return *this;
    }
 
    Matrix& operator % (int k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                this->mat[i][j] %= k;
            }
        }
        return *this;
    }
 
    void display() {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << mat[i][m-1] << endl;
        }
        for (int i = 0; i < m - 1; ++i) {
            cout << mat[n-1][i] << " ";
        }
        cout << mat[n-1][m-1] << endl;
    }
};
 
int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> vecs(n);
        for (int i = 0; i < n; ++i) {
            cin >> vecs[i];
        }
        Matrix ans(vecs);
        Matrix mul(n);
        while (k != 0) {
            //快速幂求余算法
            if (k & 1) {
                ans = ans * mul % 100;
            }
            mul = mul * mul % 100;
            k >>= 1;
        }
        ans.display();
    }
    return 0;
}