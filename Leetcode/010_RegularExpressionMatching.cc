//正则表达式，通配符*.的实现
//*代表*之前的那个字符可以匹配任意个（如果说*代表任意字符串，则是把*当成通配符来使用）
//.代表任意的单个字符
//另外s是被匹配的字符串，*和.都在p中
//并且假设p中不会出现连续的*

#include<string>
using namespace std;

//方法一，递归
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty()) {
            if (p.empty())
                return true;
            //判断p是不是"a*b*"这种形式的字符串
            if (p.size() & 1 == 1)//p字符串必须为偶数长度
                return false;
            for (int i = 1; i < p.size(); i += 2) {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }
        if (p.empty())
            return false;
        if (p.size() > 1 && p[1] == '*') {
            if (s[0] == p[0] || p[0] == '.')
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));//第二种情况是可以忽略p开头的字母加*的情况
            else return isMatch(s, p.substr(2));
        } else {
            if (s[0] == p[0] || p[0] == '.')
                return isMatch(s.substr(1), p.substr(1));
            else return false;
        }
    }
};