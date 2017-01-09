#include<string>
#include<vector>
#include<sstream>
using namespace std;

//版本号比较！
//方法1，分四种情况，分别先比较长度，长度相同再依次比较
class Solution {
public:
    int compareVersion(string version1, string version2) {
        //把开头的0去掉，这是版本号，不是数字
        int i=0;
        while(i<version1.size() && version1[i]=='0')
            i++;
        version1=version1.substr(i);
        i=0;
        while(i<version2.size() && version2[i]=='0')
            i++;
        version2=version2.substr(i);
        
        
        if(version1.empty() && version2.empty())
            return 0;
        if(version1.empty()){//这里是为了防止有"4.5"和"4.5.0.0"情况
            for(int i=0;i<version2.size();i++){
                if(version2[i]!='0' && version2[i]!='.')
                    return -1;
            }
            return 0;
        }
        if(version2.empty()){
            for(int i=0;i<version1.size();i++){
                if(version1[i]!='0' && version1[i]!='.')
                    return 1;
            }
            return 0;
        }
        
        
        bool twoParts1=false;
        bool twoParts2=false;
        std::string::size_type n1,n2;
        if((n1=version1.find('.'))!=string::npos)
            twoParts1=true;
        if((n2=version2.find('.'))!=string::npos)
            twoParts2=true;
        const int len1=version1.size();
        const int len2=version2.size();
        
        if(!twoParts1 && !twoParts2){
            if(len1>len2)
                return 1;
            else if(len1<len2)
                return -1;
            else{
                for(int i=0;i<len1;i++){
                    if(version1[i]>version2[i])
                        return 1;
                    else if(version1[i]<version2[i])
                        return -1;
                }
                return 0;
            }
        }
        if(twoParts1){
            if(twoParts2){
                if(n1>n2)
                    return 1;
                else if(n1<n2)
                    return -1;
                else {
                    for(int i=0;i<n1;i++){
                        if(version1[i]>version2[i])
                            return 1;
                        else if(version1[i]<version2[i])
                            return -1;
                    }
                    return compareVersion(version1.substr(n1+1),version2.substr(n2+1));
                }
            }
            else{
                if(n1>len2)
                    return 1;
                else if(n1<len2)
                    return -1;
                else {
                    for(int i=0;i<n1;i++){
                        if(version1[i]>version2[i])
                            return 1;
                        else if(version1[i]<version2[i])
                            return -1;
                    }
                    return compareVersion(version1.substr(n1+1),"");
                }
            }
        }
        else return (-1)*compareVersion(version2,version1);
    }
};


//方法2，切分成数字进行比较
class Solution2 {
public:
    //返回切分后转换成数字的子字符串
    vector<int>sonstr(string str){
        vector<size_t>a;
        vector<int>c;
        vector<string>b;
        for(size_t i=0;i<str.size();++i){
            if(str[i]=='.')a.push_back(i);
        }
        if(a.size()==0){
            b.push_back(str);
        }
        else{
            b.push_back(str.substr(0,a[0]));
            for(size_t i=0;i<a.size()-1;++i){//之前写错
                b.push_back(str.substr(a[i]+1,a[i+1]-a[i]-1));
            }
            b.push_back(str.substr(a[a.size()-1]+1,str.size()-1-a[a.size()-1]));
        }
        for(size_t i=0;i<b.size();++i){
            stringstream ss;
            ss<<b[i];
            int d;
            ss>>d;
            c.push_back(d);
        }
        return c;
    }
    int compareVersion(string version1, string version2) {
       long a = 0, b =0;
        int v1len = version1.length(), v2len = version2.length();
        int i = 0, j = 0;
        while (i < v1len || j < v2len) {
                a = 0; b =0;
                while (i < v1len && version1.at(i) != '.') {
                        a = a * 10 + version1.at(i) - '0';
                        ++i;
                }
                ++i;
                while (j < v2len && version2.at(j) != '.') {
                        b = b * 10 + version2.at(j) - '0';
                        ++j;
                }
                ++j;
                if (a > b) return 1;
                if (a < b) return -1;
        }
        return 0;
    }
};