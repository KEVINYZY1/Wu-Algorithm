/*
字符移位
小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
你能帮帮小Q吗？


输入描述:

输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
  


输出描述:

对于每组数据，输出移位后的字符串。

输入例子:
AkleBiCeilD

输出例子:
kleieilABCD
*/

//从后往前遍历碰到大写字母就跟后面的交换，直到遇到大写字母为止，然后再往前遍历
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
		string data;
		while (getline(cin, data)) {
 				int count = data.size();
 				for (int index = count - 1; index >= 0; index--) {
						if (data[index] >= 'A' && data[index] <= 'Z') {
								for (int tmp = index; tmp<count - 1; tmp++) {
										if (data[tmp + 1] >= 'A' && data[tmp + 1] <= 'Z') {
												break;
										}
										swap(data[tmp], data[tmp + 1]);
								}
						}
    		} 
    		cout << data << endl;
    		data.clear();
    }
		return 0;
}