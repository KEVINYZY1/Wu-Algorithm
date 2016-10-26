#include<string>
#include<limits.h>
using namespace std;

//和第十题很类似，类似于通配符的匹配
//这里的*可以表示任何字符串，包括空字符串
//?可以表示任意符号，但是不能代表空
/*
s的字符和p的字符相等
p中的字符是?，这时无论s的字符是什么都可以匹配一个
p中遇到了一个*，这时无论s的字符是什么都没关系
之前的都不符合，但是p在之前的位置有一个*，我们可以从上一个*后面开始匹配
s已经匹配完，但是p后面还有很多连续的`*
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int idxs = 0, idxp = 0, idxstar = -1, idxmatch = 0;
        while(idxs < s.length()){
            // 当两个指针指向完全相同的字符时，或者p中遇到的是?时
            if(idxp < p.length() && (s[idxs] == p[idxp] || p[idxp] == '?')){
                idxp++;
                idxs++;
            // 如果字符不同也没有?，但在p中遇到是*时，我们记录下*的位置，但不改变s的指针，方便回溯
            } else if(idxp < p.length() && p[idxp]=='*'){
                idxstar = idxp;
                idxp++;
                //遇到*后，我们用idxmatch来记录*匹配到的s字符串的位置，和不用*匹配到的s字符串位置相区分
                idxmatch = idxs;
            // 如果字符不同也没有?，p指向的也不是*，但之前已经遇到*的话，我们可以从idxmatch继续匹配任意字符
            } else if(idxstar != -1){
                // 用上一个*来匹配，那我们p的指针也应该退回至上一个*的后面
                idxp = idxstar + 1;
                // 用*匹配到的位置递增
                idxmatch++;
                // s的指针退回至用*匹配到位置
                idxs = idxmatch;
            } else 
                return false;
        }
        // 因为1个*能匹配无限序列，如果p末尾有多个*，我们都要跳过
        while(idxp < p.length() && p[idxp] == '*'){
            idxp++;
        }
        // 如果p匹配完了，说明匹配成功
        return idxp == p.length();
    }
};