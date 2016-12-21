#include<string>
#include<limits.h>
using namespace std;

//请实现一个函数，将一个字符串中的空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution {
public:
	void replaceSpace(char *str,int length) {
		//假设str所指的字符串空间可以经得住折腾
        int countSpaces=0;
        for(int i=0;i<length;i++){
            if(*(str+i)==' ')
                countSpaces++;
        }
        int newLength=countSpaces*2+length;
        for(int i=newLength,j=length;j>=0;i--,j--){
            if(*(str+j)!=' '){
                *(str+i)=*(str+j);
            }
            else{
                *(str+i)='0';
                i--;
                *(str+i)='2';
                i--;
                *(str+i)='%';
            }
        }
	}
};