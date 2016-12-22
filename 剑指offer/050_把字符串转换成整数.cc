#include<string>
#include<limits.h>
using namespace std;


class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        int index=0;
        const int len=str.size();
        while(index<len){
            if(str[index]==' ')
                index++;
            else break;
        }
        int sign=1;
        if(index<len && str[index]=='+'){
            index++;
        }
        else if(index<len && str[index]=='-'){
            index++;
            sign=-1;
        }
        int num=0;

        bool flagOverflow=false;
        while(index<len){
            if(str[index]>='0'&&str[index]<='9'){
                
                int nextNum=num*10+(str[index]-'0')*sign;//INT_MIN怎么办，这样办咯
                if(nextNum/10!=num){
					flagOverflow=true;
                    return 0;
                    break;
                }
                
                num=nextNum;
                index++;
            }
            else return 0;
        }
       // if(flagOverflow)
         //   return (sign==1)?INT_MAX:INT_MIN
         return num;
    }
};