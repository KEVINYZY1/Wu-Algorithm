#include<string>
#include<map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> romanChara;
        romanChara['I'] = 1;
        romanChara['V'] = 5;
        romanChara['X'] = 10;
        romanChara['L'] = 50;
        romanChara['C'] = 100;
        romanChara['D'] = 500;
        romanChara['M'] = 1000;
        int ret = 0;
        int increase = 1;
        for(int i = s.size() - 2; i >= 0; i--) {
            ret += increase * romanChara[s[i + 1]];
            //唯一需要考虑的情况就是当罗马数字小的在大的前面时，则小的罗马数组代表减去
            //所以我们从后往前遍历
            if (romanChara[s[i]] < romanChara[s[i + 1]])
                increase =- 1;
            else increase = 1;
        }
        ret += increase * romanChara[s[0]];
        return ret;
    }
};