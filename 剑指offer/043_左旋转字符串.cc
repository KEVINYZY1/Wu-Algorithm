#include<string>
#include<limits.h>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty())
            return str;
        const int len = str.size();
        if (n >= len)
            n %= len;
        reverse(str.begin(), str.begin() + n);
        reverse(str.begin() + n, str.end());
        reverse(str.begin(), str.end());
        return str;
    }
};