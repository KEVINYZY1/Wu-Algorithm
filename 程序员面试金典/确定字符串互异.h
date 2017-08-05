#include<string>
#include<vector>
using namespace std;


//Parition 基于快速排序的partition，可以边排序边找重复 ，也即是每次partition之后
//判断中间key元素与两边元素是否相同，相同则返回false，不同再进行下一轮partition.
//时间复杂度也是O(nlongn)，但要比排序速度快。
class Different1 {  
bool quick_check(string &str,int low,int high){
        int first = low,last = high;
        char key = str[first];
        if (low>=high)
            return true;
        while(first<last){
            while(first <last && str[last] >= key)
                last--;           
            str[first] = str[last];
            while(first<last && str[first] <= key)
                first++;
            str[last] = str[first];
        }
        str[first] = key;
        if (first>low && str[first] == str[first-1])
            return false;
        if (first<high && str[first] == str[first+1])
            return false;
        return quick_check(str,low,first-1) && quick_check(str,first+1,high);
    }
public:
    bool checkDifferent(string iniString) {
        return quick_check(iniString,0,iniString.size()-1);
    }
};


class Different2 {
public:
    bool checkDifferent(string iniString) {
        vector<int> hash(128,0);//vector<bool> 跑不过测试？？
        int len=iniString.size();
        if(len>128)
            return false;
        for(int i=0; i<len; i++){
            int temp=iniString[i];
            if(hash[temp]==0) 
                hash[temp]++;
            else return false;
        }
        return true;
    }
};