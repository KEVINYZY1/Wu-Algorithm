#ifndef KMP_H
#define KMP_H

#include<vector>
#include<string>
using namespace std;

//KMP
//使用状态机的方式解决匹配问题
//这样实现的kmp算法可以保证最坏情况也是线性的时间复杂度 O(M+N)
//针对于重复性很高的文本中查找重复性很高的匹配模式，有着较好的性能
//优点在于，不需要在被查找字符串中回退，这样的话，面对流输入的查找更为合适！！！
//缺点，KMP算法并不比最简单的c库函数strstr()快多少

static int SIZEALPH2 = 256;   //字母表的大小
class KMP1{
    public:
        KMP1(string& pat):pat_(pat), dfa_(SIZEALPH2, vector<int>(pat.size(),0)) {
            //根据匹配子字符串pat来构造状态机
            dfa_[pat_[0]][0] = 1;
            for (int i = 0, j = 1; j < pat_.size(); j++) {
                for (int k = 0; k < SIZEALPH2; k++)
                    dfa_[k][j] = dfa_[k][i];
                dfa_[pat_[j]][j] = j + 1;//如果匹配成功
                i = dfa_[pat_[j]][i];//更新重启状态
            }
        }
        int search(string &txt) {
            if (txt.empty())
                return -1;
            int i = 0, j = 0;
            for (; i < txt.size() && j < pat_.size(); i++) {
                j = dfa_[txt[i]][j];
            }
            if (j == pat_.size())
                return i - pat_.size();//返回匹配的子字符串在txt的位置
            else return - 1;//-1代表没有检查到
        }

    private:
        string pat_;
        vector<vector<int> > dfa_;
};



//利用构造的next数组，回退来实现kmp算法

class KMP2 {
    public:
        KMP2(string& pat) : pat_(pat), next_(pat.size() + 1, 0) {
            //构造next数组
            for (int i = 1; i < pat.size(); i++) {
                int temp = next_[i];
                while (temp && pat[temp] != pat[i])
                    temp = next_[temp];
                next_[i+1] = (pat[temp] == pat[i]) ? temp + 1 : 0;
            }
        }

        int search(string &txt) {
            if (txt.empty())
                return -1;

            for (int i = 0, p = 0; i < txt.size(); i++) {
                while (p && txt[i] != pat_[p])
                    p = next_[p];
                if (txt[i] == pat_[p])
                    p++;
                if (p == pat_.size())
                    return i - pat_.size() + 1;
            }
            return -1;
        }
    private:
        string pat_;
        vector<int> next_;//next数组含义，第i个字符前面的字符串和第next[i]个字符的前缀字符串是一样的
};
#endif