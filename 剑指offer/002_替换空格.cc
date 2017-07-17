#include<string>
#include<limits.h>
using namespace std;

//请实现一个函数，将一个字符串中的空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution {
public:
	void replaceSpace(char *str, int length) {
		//保证字符串数组有足够的空间去容纳变长后的字母
        int countSpaces = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ')
                countSpaces++;
        }
        if (countSpaces > 0) {
            for (int i = length - 1; i >= 0; i--) {
                if (str[i] == ' ') {
                    countSpaces--;
                    int index = countSpaces * 2 + i;
                    str[index] = '%';
                    str[index + 1] = '2';
                    str[index + 2] = '0';
                } else {
                    str[i + countSpaces * 2] = str[i];
                }
            }
        }
	}
};