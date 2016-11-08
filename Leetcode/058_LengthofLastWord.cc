#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastWhiteSpaceIndex=0;
        int result=0;
        int len=s.size()-1;
        while(len>=0 && s[len]==' ')//"a ",考虑最后一个单词的末尾还有空格的情况，或者用个prev保存result的值也可以
            len--;
        for(int i=0; i<len+1; i++){
            if(s[i]==' '){
                lastWhiteSpaceIndex=i;
                result=0;
                continue;
            }
            result++;
        }
        return result;
    }
};