#include<string>
#include<vector>
using namespace std;

//输入一个字符串,按字典序打印出该字符串中字符的所有排列。
//例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 
//输入描述:
//输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

class Solution {
public:
    vector<string> Permutation(string str) {
        
        vector<string>result;
        if(str.empty())
            return result;
        //sort(str.begin(),str.end());
        findPermutation(result,str,0,str.size()-1);
        sort(result.begin(),result.end());
        return result;
    }
    void findPermutation(vector<string>&result,string str,int start,int end){
        if(start>=end){
            result.push_back(str);
            return;
        }
        for(int i=start;i<=end;i++){
            int k;
            for(k=start;k<i;k++)
                if(str[k]==str[i])
                	break; 
            if(k<i)
                continue;
            swap(str[i],str[start]);
            findPermutation(result,str,start+1,end);//注意start的值只加1
            swap(str[i],str[start]);
        }
    }
};