#include <string>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

/*
求一个字符串中，全部数字串代表的数字之和
忽略小数点
数字左侧有'-'，奇数个为负数
*/

class Solution {
public:
    int numSum(string& str) {
        int res = 0;
        if (str.empty())
            return res;
        const int len = str.size();
        int index = 0;
        while (index < len) {
            int sign = 1;
            if (str[index] == '-') {
                int count = 1;
                while (str[index] == '-') {
                    count++;
                    index++;
                }
                if ((count & 1) == 1) {
                    sign *= -1;
                }
            }
            if (str[index] >= '0' && str[index] <= '9') {
                int temp = 0;
                while (str[index] >= '0' && str[index] <= '9') {
                    temp *= 10;
                    temp += str[index] - '0';
                    index++;
                }
                res += sign * temp;
            } else {
                index++;
            }
        }
        return res;
    }
};

int main () {
    Solution s;
    string temp1 = "abcd";
    string temp2 = "dcba";
    cout << "good" << endl;
}