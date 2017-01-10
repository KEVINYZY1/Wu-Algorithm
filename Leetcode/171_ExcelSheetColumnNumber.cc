#include<string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        if(s.empty())
            return 0;
        const int len=s.size();
        int result=0;
        int count=1;
        for(int i=len-1;i>=0;i--){
            result+=(s[i]-'A'+1)*count;
            count*=26;
        }
        return result;
    }
};