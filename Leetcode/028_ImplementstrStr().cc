#include<string>
using namespace std;
//用kmp？对一道easy题来说，是不是有点难了
//先用最蠢的双重循环，尽量优化
class Solution {
public:
    int strStr(string haystack, string needle) {
        const int haystackSize=haystack.size();
        const int needleSize=needle.size();
        if(haystackSize<needleSize)
            return -1;
        if(needle.empty())
            return 0;
        for(int i=0;i<haystackSize;i++){
            if(haystackSize-i<needleSize)
                return -1;
            if(haystack[i]!=needle[0])
                continue;
            else{
                if(needleSize==1)
                    return i;
                for(int j=1;j<needleSize;j++){
                    if(needle[j]!=haystack[i+j])
                        break;
                    if(j==needleSize-1)
                        return i;
                }
            }
        }
        return -1;
    }
};