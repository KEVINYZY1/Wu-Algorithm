/*
回文序列
如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
{1, 2, 1}, {15, 78, 78, 15} , {112} 是回文序列, 
{1, 2, 2}, {15, 78, 87, 51} ,{112, 2, 11} 不是回文序列。
现在给出一个数字序列，允许使用一种转换操作：
选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。

输入描述:
输入为两行，第一行为序列长度n ( 1 ≤ n ≤ 50)
第二行为序列中的n个整数item[i]  (1 ≤ iteam[i] ≤ 1000)，以空格分隔。


输出描述:
输出一个数，表示最少需要的转换次数

输入例子:
4
1 1 1 3

输出例子:
2
*/

//双指针法，首尾开始遍历，哪边小，就让小的一端加上自己相邻的数
//值得注意的地方，删除数组中的数通过指针移动来实现。
#include <iostream>
using namespace std;
int comb(int* nums, int head, int tail) {
    int times = 0;
    int left = nums[head], right = nums[tail];
    while (head < tail) {
        if (left < right) 
            left += nums[++head], times++;
        else if(left > right)
            right += nums[--tail], times++;
        else {
        	head++;
            tail--;
            left = nums[head];
            right = nums[tail];
        }
    }
    return times;
}
int main(){
    int n = 0;
    int nums[50] = {0};
    cin >> n;
    for( int i = 0; i < n; i++)
        cin >> nums[i];
    cout << comb(nums, 0, n-1);
}