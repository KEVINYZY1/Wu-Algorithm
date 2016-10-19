#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result;
        string s="11";
        if(n==1)
            return "1";
        if(n==2)
            return s;
        while(n>2){
            result.clear();
            for(int i=1;i<=s.size();i++){
                int count=1;
                while(s[i-1]==s[i]){
                    count++;
                    i++;
                }
                result.push_back('0'+count);
                result.push_back(s[i-1]);
            }
            s=result;
            n--;
        }
        return result;
    }
};

//stl
class Solution2 {
public:
    string countAndSay(int n) {
        string s("1");
        while (--n)
            s = getNext(s);
        return s; 
    }
    string getNext(const string &s) {
        stringstream ss;
        for (auto i = s.begin(); i != s.end(); ) {
            auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
            ss << distance(i, j) << *i;
            i = j;
        }
        return ss.str();
    }
};   