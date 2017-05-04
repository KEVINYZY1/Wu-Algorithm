/*
最大和
时间限制：1秒
空间限制：32768K
在一个N*N的数组中寻找所有横，竖，左上到右下，右上到左下，四种方向的直线连续D个数字的和里面最大的值 
输入描述:
每个测试输入包含1个测试用例，第一行包括两个整数 N 和 D :
3 <= N <= 100
1 <= D <= N
接下来有N行，每行N个数字d:
0 <= d <= 100


输出描述:
输出一个整数，表示找到的和的最大值

输入例子:
4 2
87 98 79 61
10 27 95 70
20 64 73 29
71 65 15 0

输出例子:
193
*/

#include <iostream>
#include <vector>
using namespace std;

//分别对行、列和对角线检查，保证每次检查都是O(n2)，也避免了很多无谓的计算
//如果是要比较出最大值，那么每个结果都必须计算一次
#include <iostream>
#include <vector>
using namespace std;

//分别对行、列和对角线检查，保证每次检查都是O(n2)，也避免了很多无谓的计算
//如果是要比较出最大值，那么每个结果都必须计算一次
int main(){
    int n, d;
	cin >> n >> d;
    vector<vector<int> > v(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    int res = 0;
    //行
    for(int i = 0; i < n; i++){
        int temp = 0;
        for(int j = 0; j < d; j++){
            temp += v[i][j];
        }
        res = max(res, temp);
        for(int j = d; j < n; j++){
            temp -= v[i][j-d];
            temp += v[i][j];
            res = max(res, temp);
        }
    }
    //列
    for(int i = 0; i < n; i++){
        int temp = 0;
        for(int j = 0; j < d; j++){
            temp += v[j][i];
        }
        res = max(res, temp);
        for(int j = d; j < n; j++){
            temp -= v[j-d][i];
            temp += v[j][i];
            res = max(res, temp);
        }
    }
    
    //对角线如果使用上述技巧，过于麻烦，不如直接算
    //对角线
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp = 0;
            for(int k = 0; k < d; k++){
                if(i+k >= n ||  j+k >= n) 
                    break;
                temp += v[i+k][j+k];
            }
            res = max(res, temp);
        }
    }

    //反对角线
    for(int i = 0; i < n-d+1; i++){
        for(int j = n-1; j >= 0; j--){
            int temp = 0;
            for(int k = 0; k < d; k++){
                if(i+k >= n || j-k < 0 ) 
                    break;
                temp += v[i+k][j-k];
            }
            res = max(res, temp);
        }
    }
    cout << res << endl;
}