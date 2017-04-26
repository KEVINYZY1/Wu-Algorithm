/*
奇怪的表达式求值
时间限制：1秒
空间限制：32768K
常规的表达式求值，我们都会根据计算的优先级来计算。比如*的优先级就高于+-。但是小易所生活的世界的表达式规则很简单，从左往右依次计算即可，而且小易所在的世界没有除法，意味着表达式中没有/，只有(+, - 和 *)。现在给出一个表达式，需要你帮忙计算出小易所在的世界这个表达式的值为多少 
输入描述:
输入为一行字符串，即一个表达式。其中运算符只有-,+,*。参与计算的数字只有0~9.//麻痹，当时写的时候没看到，导致考虑过于复杂，虽然写出来了，但是花了很多时间
保证表达式都是合法的，排列规则如样例所示。


输出描述:
输出一个数，即表达式的值

输入例子:
3+5*7

输出例子:
56
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main(){
    string s;
    cin >> s;
    int res = 0;
    if(s.empty()){
        cout << 0 << endl;
        return 0;
    }
    stringstream ss;
    ss << s[0];
    ss >> res;
    ss.clear(); /*故意用sstream的，每次用完要clear*/
    //假设是合格的表达式
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+'){
            int temp;
            ss << s[i + 1];
            ss >> temp;
            res += temp;
            ss.clear();
        }
        else if(s[i] == '-'){
            int temp;
            ss << s[i + 1];
            ss >> temp;
            res -= temp;
            ss.clear();
        }
        else if(s[i] == '*'){
            int temp;
            ss << s[i + 1];
            ss >> temp;
            res *= temp;
            ss.clear();
        }
    }
    cout << res << endl;
}