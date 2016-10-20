#include<string>
#include<limits.h>
using namespace std;


//字符串乘法，不能将字符串转为整数再乘，自然不需要考虑大数溢出的问题
class Solution {
public:
    string multiply(string num1, string num2) {
        const int n1=num1.size();
        const int n2=num2.size();
        if(num1=="0"||num2=="0")
            return "0";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string result(n1+n2,'0');
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int temp=(num1[i]-'0')*(num2[j]-'0');
                int unit=temp%10;
                int tens=temp/10;
                result[i+j]+=unit;
                int k=0;
                while(result[i+j+k]>'9'){
                    result[i+j+k]-=10;
                    result[i+j+k+1]+=1;
                    k++;
                }
                k=0;
                result[i+j+1]+=tens;
                while(result[i+j+k+1]>'9'){
                    result[i+j+k+1]-=10;
                    result[i+j+k+2]+=1;
                    k++;
                }
            }
        }
        int i=n1+n2-1;
        while(result[i]=='0')
            i--;
        result.erase(i+1,n1+n2-i-1);
        reverse(result.begin(),result.end());
        return result;
    }
};