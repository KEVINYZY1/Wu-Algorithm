#include<string>
#include<cassert>
#include<unordered_map>
using namespace std;

//要考虑负数
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        assert(denominator!=0);
        string result;
        if(numerator==0)
            return "0";
        if(numerator<0 ^ denominator<0) //异或，numerator<0和denominator<0仅有一个为真
            result+='-';    
        
        //转化为正数，INT_MIN转化为正数会溢出，故用long long。long long int n=abs(INT_MIN)得到的n仍然是负的，所以写成下面的形式。  
        long long int n=numerator,d=denominator;  
        n=abs(n);d=abs(d);
        result+=to_string(n/d); 
        long long int r=n%d;
        if(r==0) 
            return result;  
        else result+='.';
        
        //商存在小数
        unordered_map<int,int>map;//k-v，余数和对应字符串的下标
        int index=result.size();
        while(r!=0){
            if(map.find(r)==map.end()){
                map[r]=index++;
            }
            else{//一旦发现哈希表已经出现了余数，那么说明开始循环
                result.insert(map[r],"(");
                result+=")";
                return result;
            }
            r*=10;
            int num=r/d;
            r-=d*num;
            result+=to_string(num);
        }
        return result;
    }
};