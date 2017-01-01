#include<string>
using namespace std;

//方法1，需要考虑很多特殊情况，麻痹，题目都没说的sb情况
//例如字符串中有连续的空格，字符串开始结尾处有空格等。
class Solution {
public:
     void reverseWords(string &s) {    
        s = removeDuplicateSpace(s);  
          
        int begin = 0;    
        int end = 0;  
            
        while(end < s.size()){    
            if(s[end] == ' '){    
                swapString(s, begin, end - 1);    
                begin = end+1;    
                end = begin;    
            }    
            else{    
                end++;    
            }    
        }    
        swapString(s, begin, end - 1);    
            
        swapString(s, 0, s.size()-1);    
    }    
        
    void swapString(string &s, int begin, int end) {    
        while(end > begin){    
            char c = s[begin];    
            s[begin] = s[end];    
            s[end] = c;    
            begin++;    
            end--;    
        }    
    }  
      
    string removeDuplicateSpace(string s) { //先去掉讨厌的空格情况 
        string res;  
        int begin = 0;  
        for(; begin < s.size(); begin++) {  
            if(s[begin] != ' '){  
                break;  
            }  
        }  
        int end = s.size() - 1;  
        for(; end >= 0; end--) {  
            if(s[end] != ' '){  
                break;  
            }  
        }  
        bool is_space = false;  
        for(int i = begin; i <= end; i++) {  
            if(s[i] == ' '){  
                if(!is_space){  
                    is_space = true;  
                }  
                else{  
                    continue;  
                }  
            }  
            else{  
                is_space = false;  
            }  
            res.push_back(s[i]);  
        }  
        return res;  
    }  
};