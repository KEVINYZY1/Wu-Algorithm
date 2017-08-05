//Young氏矩阵
//杨氏矩阵是一种非常巧妙的数据结构，它既可以用来当堆，又可以用来当做平衡树。
//在这里，我们将杨氏矩阵作为最小优先队列的内部实现

#ifndef YOUNGMATRIX_H
#define YOUNGMATRIX_H
#include  <vector>
#include <limits.h>
#include <iostream>
using namespace std;

template<class T>
class youngmatrix {
public:
    //有个问题？？当类型是T的时候，如何表达T_MAX。。
    youngmatrix() {
        s = vector<vector<T> >(m, vector<T>(n, INT_MAX));
        //利用了类构造临时对象，将s赋值成m*n的矩阵，里面元素都为INT_MAX
    }
    youngmatrix(int a, int b) : m(a), n(b) {
        s = vector<vector<T> >(m, vector<T>(n, INT_MAX));
    }
    //将k插入到杨氏矩阵中，如果杨氏矩阵满了，则不插入
    void insertElement(vector<vector<T> > &s, T k);
    //获取杨氏矩阵中最小的元素
    T getMinElement(vector<vector<T> >& s);
    //获取杨氏矩阵最小元素，并且删除该元素
    T extractMinElement(vector<vector<T> >& s);
    //将第x行y列的元素的关键值降到k
    //其实和fixYoungMatrix函数是相对的！！！
    void decreaseElement(vector<vector<T> >& s, int x, int y, T k);
    //搜索关键值为k的元素，判断是否在矩阵中
    bool searchElement(vector<vector<T> >& s, T k);
private:
    int m;//杨氏矩阵的行数
    int n;//杨氏矩阵的列数
    vector<vector<T> > s;
    //从左上向右下，不断调整(x,y)位置，使得被修改的杨氏矩阵满足它的定义
    void fixYoungMatrix(vector<vector<T> >& s, int x, int y) {
        int min_x = x;
        int min_y = y;
        if (y < s[0].size() - 1 && s[x][y] > s[x][y + 1]) {
            min_y = y + 1;
        }
        if (x<s.size()-1&&s[x+1][y]>s[min_x][min_y]) {
            min_x = x + 1;
        }
        if (min_x != x && min_y != y) {
            swap(s[min_x][min_y], s[x][y]);
            fixYoungMatrix(s, min_x, min_y);
        }
    }
};

template<class T>
void youngmatrix<T>::insertElement(vector<vector<T> > & s, T k) {
    if (s[m - 1][n - 1] != INT_MAX) {
        cout << "矩阵已满" << endl;
        return;
    }
    decreaseElement(s, s.size() - 1, s[0].size() - 1, k);
}
template<class T>
T youngmatrix<T>::getMinElement(vector<vector<T> >& s) {
    assert(s[0][0] != INT_MAX);
    return s[0][0];
}

template<class T>
T youngmatrix<T>::extractMinElement(vector<vector<T> >& s) {
    assert(s[0][0] != INT_MAX);
    T result = s[0][0];
    swap(s[0][0], s[s.size() - 1][s[0].size() - 1]);
    fixYoungMatrix(s, 0, 0);
}

template<class T>
void youngmatrix<T>::decreaseElement(vector<vector<T> >&s, int x, int y, T k) {
    assert(k <= s[x][y]);
    s[x][y] = k;
    while (x >= 0 && y >= 0) {
        int up=INT_MIN;
        int left=INT_MIN;
        if (x > 0)
            up = s[x-1][y];
        if (y > 0)
            left = s[x][y-1];
        if (s[x][y] >= up && s[x][y] >= left)
            break;
        else if (s[x][y] < up) {
            swap(s[x][y], s[x-1][y]);
            x--;
        } else {
            swap(s[x][y], s[x][y-1]);
            y--;
        }
    }
}

template<class T>
bool youngmatrix<T>::searchElement(vector<vector<T> >& s, T k) {
    if (s[0][0] == INT_MAX)
        return false;
    int y = n-1;
    int x=0;
    while(x>=0&&y<m){
        if(s[x][y]<k){
            y--;
        }
        else if(s[x][y]>k){
            x++;
        }
        else return true;
    }
    return false;
}
#endif