/*
开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。
 
输入：
 
合法坐标为A(或者D或者W或者S) + 数字（两位以内）
 
坐标之间以;分隔。
 
非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。
 
下面是一个简单的例子 如：
 
A10;S20;W10;D30;X;A1A;B10A11;;A10;
 
处理过程：
 
起点（0,0）
 
+   A10   =  （-10,0）
 
+   S20   =  (-10,-20)
 
+   W10  =  (-10,-10)
 
+   D30  =  (20,-10)
 
+   x    =  无效
 
+   A1A   =  无效
 
+   B10A11   =  无效
 
+  一个空 不影响
 
+   A10  =  (10,-10)
 
 
 
结果 （10， -10）


输入描述:
一行字符串


输出描述:
最终坐标，以,分隔
示例1
输入

A10;S20;W10;D30;X;A1A;B10A11;;A10;
输出

10,-10
*/

#include <iostream>
#include <string>
using namespace std;

//不考虑空格
//如果str末尾不是';' 则需要检验index不越界
void move(int& x, int& y, string& str, int& index) {
    int end = str.find_first_of(';', index);
    if (end - index < 2 || end - index > 3) {//这个判断很省事
        index = end + 1;
        return;
    }
    char a = str[index];
    index++;
    int temp = 0;
    //最多提取两位数字
    if (str[index] <= '9' && str[index] >= '0') {
    	temp += str[index] - '0';
    	index++;
    	if (str[index] <= '9' && str[index] >= '0') {
    		temp *= 10;
        	temp += str[index] - '0';
        	index++;
        }
    }
    if (index == end) {
        switch(a) {
        	case 'A':
                x -= temp; 
                break;
            case 'S':
                y -= temp; 
                break;
            case 'D':
                x += temp; 
                break;
            case 'W':
                y += temp; 
                break;
            default :
                break;
        }
    } else {
        index = end;
    }
    index++;
}

int main() {
    string str;
    //没有这个就是错的，看来是一次输入好几组，记得注意，牛客网不行
    while(getline(cin, str)){
        int x = 0, y = 0;
        int index = 0;
        int len = str.find_last_of(';');
        while (index <= len) {
            move(x, y, str, index);
        }
        cout << x << "," << y << endl;
    }
}