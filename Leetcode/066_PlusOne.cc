#include<vector>
using namespace std;

//考虑一下首位溢出
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        while(i>=0){
            digits[i]+=1;
            if(digits[i]==10){
                digits[i]=0;
                i--;
            }
            else break;
        }
        if(i==-1){
            digits.insert(digits.begin(),1);
            return digits;
        }
        else return digits;
    }
};