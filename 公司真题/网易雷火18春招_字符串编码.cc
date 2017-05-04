/*
字符串编码
时间限制：1秒
空间限制：32768K
给定一个字符串，请你将字符串重新编码，将连续的字符替换成“连续出现的个数+字符”。比如字符串AAAABCCDAA会被编码成4A1B2C1D2A。 
输入描述:
每个测试输入包含1个测试用例
每个测试用例输入只有一行字符串，字符串只包括大写英文字母，长度不超过10000。


输出描述:
输出编码后的字符串

输入例子:
AAAABCCDAA

输出例子:
4A1B2C1D2A
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    string res;
    char last = 'f';
    if(!s.empty())
    	last = s[0];
    int count = 1;
    for(int i = 1; i < s.size(); i++){
        if(last != s[i]){
            res += to_string(count) + last;
            last = s[i];
            count = 1;
        }
        else{
            count++;
        }
    }
    if(last != 'f'){//最后判断
        res += to_string(count) + last;
    }
    cout << res << endl;
}