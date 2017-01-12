#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

//方法1，直接使用哈希容器，每个10字符长度的字符串都存入哈希表中
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        const int len=s.size();
        if(len<=10)
            return result;
        unordered_map<string,int> m;//完全依赖于哈希表
        for(int i=0;i<len-9;i++){
            string temp=s.substr(i,10);
            if(m.find(temp)!=m.end()){
                m[temp]++;
                if(m[temp]==2)
                    result.push_back(temp);
            }
            else m[temp]=1;
        }
        return result;
    }
};

//由于要存入的字符串只有10位，并且每位只会出现A, C, G, and T四种字符，故可以设计更好的哈希函数
//子串只有10位，且每一位只可能有4种不同的字母，那我们可以用4^10个数字来表示每种不同的序列，因为4^10=2^20<2^32所以我们可以用一个Integer来表示
class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        const int len=s.size();
        if(len<=10)
            return result;
        unordered_map<int,int> m;
        for(int i=0;i<len-9;i++){
            string temp=s.substr(i,10);
            int code=hash(temp);
            if(m.find(code)!=m.end()){
                m[code]++;
                if(m[code]==2)
                    result.push_back(temp);
            }
            else m[code]=1;
        }
        return result;
    }
private:
    int hash(string &s){
        int code=0;
        for(int i=0;i<10;i++){
            code<<=2;
            switch(s[i]){
                case 'A': code += 0; break;
                case 'C': code += 1; break;
                case 'T': code += 2; break;
                case 'G': code += 3; break;
            }
        }
        return code;
    }
};

//也可以直接bool b[1024*1024]数组，来存放2的20次方的结果可能。