/*
添加字符
时间限制：1秒
空间限制：32768K
牛牛手里有一个字符串A，羊羊的手里有一个字符串B，B的长度大于等于A，所以牛牛想把A串变得和B串一样长，这样羊羊就愿意和牛牛一起玩了。
而且A的长度增加到和B串一样长的时候，对应的每一位相等的越多，羊羊就越喜欢。比如"abc"和"abd"对应相等的位数为2，为前两位。
牛牛可以在A的开头或者结尾添加任意字符，使得长度和B一样。现在问牛牛对A串添加完字符之后，不相等的位数最少有多少位？ 
输入描述:
第一行为字符串A，第二行为字符串B，A的场地小于等于B的长度，B的长度小于等于50.字符均为小写字母。


输出描述:
输出一个整数表示A串添加完字符之后，不相等的位数最少有多少位？

输入例子:
abe
cabc

输出例子:
1
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
 
//想的过于复杂了= =，没有好办法，就暴力
int main(){
    string a, b;
    cin >> a >> b;
    int maxs = 0;
    for(int i = 0; i <= b.size()-a.size(); i++){
        int count = 0;
        for(int j = 0; j < a.size(); j++){
            if(a[j] == b[j+i]){
                count++;
            }
        }
        maxs = max(maxs, count);
    }
    cout << a.size()-maxs << endl;
}