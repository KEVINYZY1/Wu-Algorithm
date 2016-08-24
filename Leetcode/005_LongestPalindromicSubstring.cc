#include<string>
using namespace std;

//方法一 暴力穷举法O(N3) 判断每个子字符串 不可取
//方法二 用动态规划优化暴力穷举法，去掉重复的判断，依然需要O(N2)的时间复杂度和空间复杂度，待补上代码

//方法三 中心判断法，时间复杂度O(n2) 空间复杂度O(1)，长度为n的字符串s里面一共有2n-1个中心，我们依次判断，找出结果
class Solution1 {
public:
    string longestPalindrome(string s) {
        string result,temp;
        for(int i=0;i<s.size();++i){
            temp=findLongestPalindrome(s,i);
            if(temp.size()>result.size()){
                result=temp;
            }
        }
        for(int i=0;i<s.size()-1;++i){
            temp=findLongestPalindrome(s,i,i+1);
            if(temp.size()>result.size()){
                result=temp;
            }
        }
        return result;
    }
private:
    string findLongestPalindrome(string s,int pos) {
        int i=1;
        while((pos-i)>=0&&(pos+i)<s.size()){
            if (s[pos-i]!=s[pos+i])
                break;
            ++i;
        }
        return s.substr(pos-i+1,2*i-1);
    }
    string findLongestPalindrome(string s,int pos1,int  pos2) {
        int i=0;
        while((pos1-i)>=0&&(pos2+i)<s.size()){
            if (s[pos1-i]!=s[pos2+i])
                break;
            ++i;
        }
        return s.substr(pos1-i+1,2*i);
    }
};

//方法四 一个O(N)时间和空间复杂度的算法(Manacher)
class Solution2 {
public:
    string longestPalindrome(string s) {
        string T = preProcess(s);
        int length = T.length();
        vector<int> p (length,0);
        int C = 0, R = 0;
        for (int i = 1; i < length - 1; i++){
            int i_mirror = C - (i - C);
            int diff = R - i;
            if (diff >= 0){
                if (p[i_mirror] < diff)//i的对称点的回文长度在C的大回文范围内部
                    p[i] = p[i_mirror]; 
                else{
                    p[i] = diff;
                    //i处的回文可能超出C的大回文范围了
                    while (T.at(i + p[i] + 1) == T.at(i - p[i] - 1))
                        p[i]++;
                    C = i;
                    R = i + p[i];
                }
            }
            else{
                p[i] = 0;
                while (T.at(i + p[i] + 1) == T.at(i - p[i] - 1))
                    p[i]++;
                C = i;
                R = i + p[i];
            }
       } 
       int maxLen = 0;
       int centerIndex = 0;
       for (int i = 1; i < length - 1; i++) {
           if (p[i] > maxLen) {
             maxLen = p[i];
             centerIndex = i;
           }
       }
       return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}
private:
//为了方便比较偶数中心的回文，在字符串中每个位置添加#
//$^是为了方便边界检测
    string preProcess(string s) {
         int n = s.length();
         if (n == 0) return "^$";
         string ret = "^";
         for (int i = 0; i < n; i++)
         {
             ret += "#" + s.substr(i, 1);
         }
         
         ret += "#$";
         return ret;
    }
};