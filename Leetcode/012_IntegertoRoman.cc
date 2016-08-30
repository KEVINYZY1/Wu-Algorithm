#include<string>
#include<vector>
using namespace std;

//罗马数字最多只能连用三个，题目限定了输入num的范围是在1~3999
class Solution {
public:
    string intToRoman(int num) {
        vector<string>units={"I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string>tens={"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string>hundreds={"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string>thousand={"M","MM","MMM"};
        string result;
        if(num>=1000){
            int temp=num/1000;
            result+=thousand[temp-1];
            num%=1000;
        }
        if(num>=100){
            int temp=num/100;
            result+=hundreds[temp-1];
            num%=100;
        }
        if(num>=10){
            int temp=num/10;
            result+=tens[temp-1];
            num%=10;
        }
        if(num>=1){
            int temp=num/1;
            result+=units[temp-1];
        }
        return result;
    }
};