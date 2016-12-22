#include<string>
#include<limits.h>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string){
        auto s=string;
        if(s==NULL||*s=='\0')
            return false;
        int i=0;
        int len=0;
        while(s[len]!='\0')
            len++;
        
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
            else if((s[i]=='e'||s[i]=='E') && !onceE){
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
                if(indexE==0 || indexE==len-1)
                    return false;
                if(indexE<indexPoint)
                    return false;
                else {
                    if((indexE-1)!=indexPoint){//这里要加双括号，不然就是下面的if和else配对了
                        if(s[indexE-1]==' ')
                            return false;
                        if(!onceAfterE && s[indexE+1]==' ')
                            return false;
                        if(onceAfterE && (indexE==len-2 || s[indexE+2]==' '))
                            return false;
                    }
                    else {
                        if(indexE==1 || s[indexE-2]==' ' || s[indexE-2]=='-' || s[indexE-2]=='+')
                            return false;
                        if(!onceAfterE && s[indexE+1]==' ')
                            return false;
                        if(onceAfterE && (indexE==len-2 || s[indexE+2]==' '))
                            return false;
                    }
                }
            }
            else{//没有小数点的情况
                if(indexE==0 || indexE==len-1)
                    return false;
                if(s[indexE-1]==' ' || s[indexE-1]=='+' || s[indexE-1]=='-')
                    return false;
                if(!onceAfterE && s[indexE+1]==' ')
                        return false;
                if(onceAfterE && (indexE==len-2 || s[indexE+2]==' '))
                        return false;
            }
        }
        return true;
    }

};