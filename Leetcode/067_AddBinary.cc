#include<string>
using namespace std;

//二进制相加
class Solution {
public:
    string addBinary(string a, string b) {
        const int lenA=a.size();
        const int lenB=b.size();
        if(!lenA)
            return b;
        if(!lenB)
            return a;
        int carry=0;
        if(lenA<lenB)//保证a长度大于b
            return addBinary(b,a);
        int i=lenA-1;
        int j=lenB-1;
        while(i>=0 && j>=0){
            int sum=a[i]-'0'+b[j]-'0'+carry;
            if(sum>=2){
                carry=1;
                a[i]=sum-2+'0';
            }else{
                a[i]=sum+'0';
                carry=0;
            }
            i--;
            j--;
        }
        if(carry==1){
            while(i>=0){
                int sum=a[i]-'0'+carry;
                if(sum==2){
                    carry=1;
                    a[i]='0';
                }
                else{
                    a[i]=sum+'0';
                    carry=0;
                    break;
                }
                i--;
            }
            if(carry==1)
                a.insert(a.begin(),'1');
        }
        return a;
    }
};