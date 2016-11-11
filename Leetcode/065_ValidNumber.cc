#include<string>
using namespace std;

//atoi的进阶题目，主要思考各种边界条件
//一旦数字开始，中间不能有空格，且能出现的只能是e或者.，它们只能出现一次
//数字结束后，字符串便只能有空格
//e需要特殊注意，前面要有数字，后面也要有数字
//e和.混合出现的情况，e后面不能是小数
//e后面也可以加正负号
//还要考虑开头有没有正负号，给跪了

//方法1，强行肛
class Solution1 {
public:
    bool isNumber(string s) {
        if(s.empty())
            return false;
        int i=0;
        const int len=s.size();
        //去掉空格
        while(i<len && s[i]==' ')
            i++;
        //看有没有正负号
        if(i+1<len && (s[i]=='-' || s[i]=='+'))
            i++;
        bool onceNum=false;
        bool onceE=false;
        bool oncePoint=false;
        bool onceAfterE=false;
        int indexE=0;
        int indexPoint=0;
        for(;i<len;i++){
            if(s[i]>='0' && s[i]<='9'){
                onceNum=true;
                continue;
            }
            else if(s[i]=='e' && !onceE){
                onceE=true;
                indexE=i;
                if(i+1<len && (s[i+1]=='+' || s[i+1]=='-')){
                    i++;
                    onceAfterE=true;
                }
            }
            else if(s[i]=='.' && !oncePoint){
                oncePoint=true;
                indexPoint=i;
            }
            else if(s[i]==' ')
                break;
            else return false;
        }
        //末尾只可以空格出现，而不能有其他字符
        while(i<len && s[i]==' ')
            i++;
        if(i!=len)
            return false;
        /*if(!onceNum && !onceE && !oncePoint)//全是空格，那么就不是数字
            return true;*/
        if(!onceNum )
            return false;
        //处理e的特殊情况
        if(onceE){
            if(oncePoint){//有小数点的情况
                if(indexE==0 || indexE==s.size()-1)
                    return false;
                if(indexE<indexPoint)
                    return false;
                else {
                    if((indexE-1)!=indexPoint){//这里要加双括号，不然就是下面的if和else配对了
                        if(s[indexE-1]==' ')
                            return false;
                        if(!onceAfterE && s[indexE+1]==' ')
                            return false;
                        if(onceAfterE && (indexE==s.size()-2 || s[indexE+2]==' '))
                            return false;
                    }
                    else {
                        if(indexE==1 || s[indexE-2]==' ' || s[indexE-2]=='-' || s[indexE-2]=='+')
                            return false;
                        if(!onceAfterE && s[indexE+1]==' ')
                            return false;
                        if(onceAfterE && (indexE==s.size()-2 || s[indexE+2]==' '))
                            return false;
                    }
                }
            }
            else{//没有小数点的情况
                if(indexE==0 || indexE==s.size()-1)
                    return false;
                if(s[indexE-1]==' ' || s[indexE-1]=='+' || s[indexE-1]=='-')
                    return false;
                if(!onceAfterE && s[indexE+1]==' ')
                        return false;
                if(onceAfterE && (indexE==s.size()-2 || s[indexE+2]==' '))
                        return false;
            }
        }
        return true;
    }
};

//方法2，正则库，

//方法3，有限状态机，非常吊，学习一下
/*
先枚举一下各种合法的输入情况：

1.空格+ 数字 +空格

2.空格+ 点 + 数字 +空格

3.空格+ 符号 + 数字 +　空格

4.空格 + 符号 + 点 +　数字　＋空格

5.空格 + (1, 2, 3, 4） + e +　(1, 2, 3, 4) +空格

组后合法的字符可以是：

1.数字

2.空格

有限状态机的状态转移过程：

起始为0：

　　当输入空格时，状态仍为0，

　　输入为符号时，状态转为3，3的转换和0是一样的，除了不能再接受符号，故在0的状态的基础上，把接受符号置为-1；

　　当输入为数字时，状态转为1, 状态1的转换在于无法再接受符号，可以接受空格，数字，点，指数；状态1为合法的结束状态；

　　当输入为点时，状态转为2，状态2必须再接受数字，接受其他均为非法；

　　当输入为指数时，非法；

状态1：

　　接受数字时仍转为状态1，

　　接受点时，转为状态4，可以接受空格，数字，指数，状态4为合法的结束状态，

　　接受指数时，转为状态5，可以接受符号，数字，不能再接受点，因为指数必须为整数，而且必须再接受数字；

状态2：

　　接受数字转为状态4；

状态3：

　　和0一样，只是不能接受符号；

状态4：

　　接受空格，合法接受；

　　接受数字，仍为状态4；

　　接受指数，转为状态5，

状态5：

　　接受符号，转为状态6，状态6和状态5一样，只是不能再接受符号，

　　接受数字，转为状态7，状态7只能接受空格或数字；状态7为合法的结束状态；

状态6：

　　只能接受数字，转为状态7；

状态7：

　　接受空格，转为状态8，状态7为合法的结束状态；

　　接受数字，仍为状态7；

状态8：

　　接受空格，转为状态8，状态8为合法的结束状态；
*/
class Solution3 {
public:
    bool isNumber(string s) {
        enum InputType
        {
            INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXPONENT,   // 5
            NUM_INPUTS  // 6
        };
        
        int transitionTable[][NUM_INPUTS] =
        {
            -1,  0,  3,  1,  2, -1,     // next states for state 0
            -1,  8, -1,  1,  4,  5,     // next states for state 1
            -1, -1, -1,  4, -1, -1,     // next states for state 2
            -1, -1, -1,  1,  2, -1,     // next states for state 3
            -1,  8, -1,  4, -1,  5,     // next states for state 4
            -1, -1,  6,  7, -1, -1,     // next states for state 5
            -1, -1, -1,  7, -1, -1,     // next states for state 6
            -1,  8, -1,  7, -1, -1,     // next states for state 7
            -1,  8, -1, -1, -1, -1,     // next states for state 8
        };
        
        int state = 0;
        int i=0;
        while (i<s.size())
        {
            InputType inputType = INVALID;
            if (isspace(s[i]))
                inputType = SPACE;
            else if (s[i] == '+' || s[i] == '-')
                inputType = SIGN;
            else if (isdigit(s[i]))
                inputType = DIGIT;
            else if (s[i] == '.')
                inputType = DOT;
            else if (s[i] == 'e' || s[i] == 'E')
                inputType = EXPONENT;
            state = transitionTable[state][inputType];
            if (state == -1)
                return false;
            else
                ++i;
        }
        
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};