/*
题目描述
编写一个程序，将输入字符串中的字符按如下规则排序。
规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。
       如，输入： Type   输出： epTy
规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。
     如，输入： BabA   输出： aABb
规则 3 ：非英文字母的其它字符保持原来的位置。
     如，输入： By?e   输出： Be?y
样例：
    输入：
   A Famous Saying: Much Ado About Nothing(2012/8).
    输出：
   A  aaAAbc   dFgghh :  iimM   nNn   oooos   Sttuuuy  (2012/8).

输入描述:

输出描述:

示例1
输入

A Famous Saying: Much Ado About Nothing (2012/8).
输出

A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//考排序的理解，规则1，2很好实现，规则3如何保持原来的位置

bool isLetter(char ch){
    if((ch>='a'&& ch<='z') || (ch>='A'&& ch<='Z'))
        return true;
    return false;
}
 
//冒泡排序
void bubbleSort(string& str){
    int sz = str.size();
    for(int k = sz-1; k >= 0; --k){
        int i = 0, j = 0;
        while(j <= k){
            if(isLetter(str[j])){
                if(tolower(str[i]) > tolower(str[j]))
                    swap(str[i], str[j]);
                i = j;
            }
            ++j;
        }
    }
}
 
int main(){
    string str;    
    while(cin>>str){      
        bubbleSort(str);
        cout<<str<<endl;
    }
    return 0;
}