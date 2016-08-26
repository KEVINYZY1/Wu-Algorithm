#include<string>
#include<vector>
using namespace std;
//一道数学题，第一次做能想出来，第二次反而想不出来了
class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        if(numRows==1)return s;
        vector<string>temp(numRows,"");
        int row=0;
        int increase=-1;
        for(int i=0;i<s.size();i++){
            if((i%(numRows-1))==0)increase*=-1;
            temp[row].push_back(s[i]);
            row+=increase;
        }
        for(int i=0;i<numRows;++i){
            result+=temp[i];
        }
        return result;
    }
};