#include<string>
#include<vector>
using namespace std;

//要求每一个解，回溯法
//每个数大小需要在0到255之间
//已经默认输入的都是数字
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if(s.empty())
            return result;
        findVaildIpAddress(result,s,0,0,"");
        return result;
    }
private:
    void findVaildIpAddress(vector<string> &result, string &s, int count, int index, string ip){
        if(count==4){
            if(index==s.size())
                result.push_back(ip);
            return;
        }
        if(!ip.empty())
            ip+='.';
        const int len=s.size();
        if(s[index]!='0'){
            if(index+2<len){
                int sum=(s[index]-'0')*100+(s[index+1]-'0')*10+(s[index+2]-'0');
                if(sum>=0 && sum<=255)
                    findVaildIpAddress(result,s,count+1,index+3,ip+s.substr(index,3));
            }
            if(index+1<len)
                findVaildIpAddress(result,s,count+1,index+2,ip+s.substr(index,2));
            if(index<len)
                findVaildIpAddress(result,s,count+1,index+1,ip+s.substr(index,1));
        }else{
            findVaildIpAddress(result,s,count+1,index+1,ip+s.substr(index,1));
        }
    }
};