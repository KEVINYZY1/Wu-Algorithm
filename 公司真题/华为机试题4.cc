/*
密码要求:
1.长度超过8位
 
2.包括大小写字母.数字.其它符号,以上四种至少三种
 
3.不能有相同长度超2的子串重复
 
说明:长度超过2的子串

输入描述:
一组或多组长度超过2的子符串。每组占一行

输出描述:
如果符合要求输出：OK，否则输出NG
示例1
输入

021Abc9000
021Abc9Abc1
021ABC9000
021$bc9000
输出

OK
NG
NG
OK
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        const int len = str.size();
        if (len <= 8) {
            cout << "NG" << endl;
            continue;
        }
        bool bigAlpha = false, smallAlpha = false, num = false, otherSign = false;
        int count = 0;
        for (auto item : str) {
            if (item >= 'a' && item <= 'z') {
                if (!bigAlpha) {
                    count++;
                    bigAlpha = true;
                } 
            } else if (item >= 'A' && item <= 'Z') {
                if (!smallAlpha) {
                    count++;
                    smallAlpha = true;
                }
            } else if (item >= '0' && item <= '9') {
                if (!num) {
                    count++;
                    num = true;
                }
            } else {
                if (!otherSign) {
                    count++;
                    otherSign = true;
                }
            }
        }
        if (count < 3) {
            cout << "NG" << endl;
            continue;
        }
        //关键：长度超过2的子串
        //哈希，每个长度为3的子字符串都放入集合中
        unordered_set<string> s;
        bool fuck = false;
        for (int i = 0; i < len - 2; ++i) {
            string ss = str.substr(i, 3);
            if (s.find(ss) != s.end()) {
                fuck = true;
            } else s.insert(ss);
        }
        if (fuck) {
            cout << "NG" << endl;
            continue;
        }
        cout << "OK" << endl;
    }
}