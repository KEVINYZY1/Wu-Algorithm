#include<string>
#include<limits.h>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty())
            return str;
        const int len=str.size();
        bool hasSpace=false;//小心没有空格的情况。
        for(int i=0;i<len;i++){
            if(str[i]==' '){
                hasSpace=true;
            }
        }
        if(!hasSpace)
            return str;
        reverse(str.begin(),str.end());
        int start=0;
        int length=0;
        for(int i=0;i<len;i++){
            if(str[i]==' '){
                reverse(str.begin()+start,str.begin()+start+length);
                start=i+1;
                length=0;
            }
            else{
                length++;
            }
        }
        reverse(str.begin()+start,str.begin()+start+length);
        return str;
    }
};