#include<string>
#include<vector>
using namespace std;

//在一个字符串
//(1<=字符串长度<=10000，全部由大写字母组成)中找到第一个只出现一次的字符,并返回它的位置

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty())
            return -1;
        //可以不用pair，第二次直接遍历str，看哪个在hash表最先是1，谁就是最早第一个。
        vector<pair<int,int> > hash(256, make_pair(0, -1));
        for (int i = 0; i < str.size(); i++) {
            char a = 0;
            hash[str[i] - a].first++;
            if (hash[str[i] - a].second == -1)
                hash[str[i] - a].second = i;
        }
        int result = 10001;
        for (int i = 0; i < 256; i++) {
            if (hash[i].first == 1)
                result = min(result, hash[i].second);
        }
        return result;
    }
};