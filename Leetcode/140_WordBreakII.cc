#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

//先dp，再dfs
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_map<int, vector<string>> memo {{s.size(), {""}}};
        function<vector<string>(int)> sentences = [&](int i) {
            if (!memo.count(i))
                for (int j=i+1; j<=s.size(); j++)
                    if (wordDict.count(s.substr(i, j-i)))
                        for (string tail : sentences(j))
                            memo[i].push_back(s.substr(i, j-i) + (tail=="" ? "" : ' ' + tail));
            return memo[i];
        };
        return sentences(0);
    }
};