#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include<vector>
#include<string>
using namespace std;


//BoyerMoore算法
//该算法从模式串的尾部开始匹配，且拥有在最坏情况下O(N)的时间复杂度。在实践中，比KMP算法的实际效能高。
//坏字符规则：当文本串中的某个字符跟模式串的某个字符不匹配时，我们称文本串中的这个失配字符为坏字符，此时模式串需要向右移动
    //移动的位数 = 坏字符在模式串中的位置 - 坏字符在模式串中最右出现的位置。此外，如果"坏字符"不包含在模式串之中，则最右出现位置为-1。
//好后缀规则：当字符失配时，后移位数 = 好后缀在模式串中的位置 - 好后缀在模式串上一次出现的位置，且如果好后缀在模式串中没有再次出现，则为-1。
//每次后移这两个规则之中的较大值。这两个规则的移动位数，只与模式串有关，与原文本串无关。
//这里的实现只考虑了坏字符串的规则！
static int SIZEALPH=256;  //字母表的大小
class BoyerMoore{
    public:
        BoyerMoore(string& pat):pat_(pat), next_(SIZEALPH,0){
            //构造next数组
            for (int c = 0; c < SIZEALPH; c++)
                next_[c] = -1;//如果"坏字符"不包含在模式串之中，则最右出现位置为-1。
            for (int j = 0; j < pat.size(); j++)
                next_[pat[j]] = j;//坏字符在模式串中最右出现的位置
        }

        int search(string &txt){
            if(txt.empty())
                return -1;
            int skip=0;
            for(int i=0; i<=txt.size()-pat_.size(); i+=skip){
                skip=0;
                for(int j=pat_.size()-1; j>=0; j--){//倒序
                    if(pat_[j]!=txt[i+j]){
                        //移动的位数skip = 不匹配字符在模式串中的位置 - 坏字符在模式串中最右出现的位置
                        skip=max(1, j-next_[txt[i+j]]);
                        break;
                    }
                }
                if(skip==0)
                    return i;
            }
            return -1;//-1代表没有检查到
        }
    private:
        string pat_; 
        vector<int> next_; 
};
#endif