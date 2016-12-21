#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string s;
        if(numbers.empty())
            return s;
        sort(numbers.begin(),numbers.end(),[](int l,int r){
            string sl=to_string(l);
            string sr=to_string(r);
            string lr=sl+sr;
            string rl=sr+sl;
            int num=strcmp(lr.c_str(),rl.c_str());
            return num>=0?false:true;
        });
        for(int i=0;i<numbers.size();i++){
            s+=to_string(numbers[i]);
        }
        return s;
    }
};