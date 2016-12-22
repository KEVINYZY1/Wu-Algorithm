#include<string>
using namespace std;

//要求只考虑字符串中的字母和数字，另外字母大小写不影响
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        const int len=s.size();
        int start=0;
        int end=len-1;
        
        while(start<end){
            while(start<len && !isAlpha(s[start]))
                start++;
            while(end>=0 && !isAlpha(s[end]))
                end--;
            if(start>=end)
                break;
            if(s[start]!=s[end])
                return false;
            else {
                start++;
                end--;
            }
        }
        return true;
    }
private:
    bool isAlpha(char &a){
        if(a>='a'&&a<='z')
            return true;
        if(a>='A'&&a<='Z'){
            a+='a'-'A';
            return true;
        }
        if(a>='0'&&a<='9')
            return true;
        return false;
    }
};