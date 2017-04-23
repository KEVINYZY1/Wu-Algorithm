/*
魔法权值
给出 n 个字符串，对于每个 n 个排列 p，按排列给出的顺序(p[0] , p[1] … p[n-1])依次连接这 n 个字符串都能得到一个长度为这些字符串长度之和的字符串。所以按照这个方法一共可以生成 n! 个字符串。
一个字符串的权值等于把这个字符串循环左移 i 次后得到的字符串仍和原字符串全等的数量，i 的取值为 [1 , 字符串长度]。求这些字符串最后生成的 n! 个字符串中权值为 K 的有多少个。
注：定义把一个串循环左移 1 次等价于把这个串的第一个字符移动到最后一个字符的后面。

输入描述:
每组测试用例仅包含一组数据，每组数据第一行为两个正整数 n, K ， n 的大小不超过 8 ， K 不超过 200。接下来有 n 行，每行一个长度不超过 20 且仅包含大写字母的字符串。


输出描述:
输出一个整数代表权值为 K 的字符串数量。

输入例子:
3 2
AB
RAAB
RA

输出例子:
3
*/


//K 的最小值是 1，全排列算法 + 偏移与原串相等（KMP）
#include <iostream>
#include <vector>
#include <assert.h>
#include <cstring> // for strncmp
#include <algorithm> // for std::next_permutation
using namespace std;
 
bool is_eq_after_move(const string& str, const size_t offset) {
    const size_t len = str.size();
    if (offset == len) return true;
     
    assert(offset >= 1 && offset < len);
    // 左移 offset 位数后，与原串相等的情况之一：
    //      每 offset 个数据块 都要相等
    //      所以 这种情况 的字符串，长度首先必须是 offset 的 整数倍。
    //
    // 情况之二，串长不是 offset 的 整数倍，像这种: ABABAB , offset = 4
    // 这种情况可以用递归来化解:
    if (len % offset != 0) {  
        if (len % offset > len / 2) return false; // 加上此句可减少复杂度
        return is_eq_after_move(str, len % offset);
    }
     
    // 程序能走到这的都是 之前提到的 情况一:
    char* s = (char*)&str[0]; // 先指向首地址
    for (size_t loop = 0, max_loop = len / offset - 1;
            loop < max_loop; ++loop) {
        if ( 0 != strncmp(s, s + offset, offset) ) {
            return false;
        }
        s += offset;
    }
    return true;
}
 
void get_ret(size_t& ret, const int* pos, const size_t size,
             const vector<string>& input, const size_t K) {
    size_t count = 1; // 自身整体移动算一个
    string newstring;
    for (size_t i = 0; i < size; ++i) {
        newstring += input[pos[i]];
    }
 
    const int len = newstring.size();
    for (int offset = 1; offset < len; ++offset) {
        // 只判断 和第一个相等的字符即可
        if (newstring[offset] == newstring[0]) {
            if (is_eq_after_move(newstring, offset)) {
                count++;
            }
        }
    }
 
    if (count == K) {
        ret++;
    }
}
 
int main() {
    size_t n, K;
    cin >> n >> K;
    vector<string> input(n);
    size_t newstrlen = 0;
    for (size_t i = 0; i < n; ++i) {
        cin >> input[i];
        newstrlen += input[i].size();
    }
     
    // 生成 0 ~ n-1 的全排列
    int pos[n];
    for (int i = 0; i < n; ++i) pos[i] = i;
 
    size_t ret = 0;
    do {
        get_ret(ret, pos, n, input, K);
    } while (std::next_permutation(pos, pos + n));
 
    cout << ret << endl;
    return 0;
}