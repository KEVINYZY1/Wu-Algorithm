#include<string>
#include<limits.h>
using namespace std;

/*
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/

class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty())
            return str;
        const int len = str.size();
        bool hasSpace = false;//小心没有空格的情况。
        for (int i = 0; i < len; i++) {
            if (str[i] == ' ') {
                hasSpace = true;
            }
        }
        if (!hasSpace)
            return str;
        reverse(str.begin(), str.end());
        int start = 0;
        int length = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == ' ') {
                reverse(str.begin() + start, str.begin() + start + length);
                start = i + 1;
                length = 0;
            }
            else{
                length++;
            }
        }
        reverse(str.begin()+start,str.begin()+start+length);
        return str;
    }
};