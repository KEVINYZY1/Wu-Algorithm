#include<vector>
#include<map>
#include<multiset>
#include<string>
#include<unordered_map>
using namespace std;

//stl，暴力解法
class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        map<multiset<char>,vector<string>> allStringSet;
        for(int i=0;i<strs.size();i++){
            allStringSet[multiset<char>(strs[i].begin(),strs[i].end())].push_back(strs[i]);
        }
        for(auto i=allStringSet.begin();i!=allStringSet.end();i++){
            result.push_back(i->second);
        }
        return result;
    }
};

//使用了哈希函数，而不是红黑树，并且使用sort排序了key，而不是用multiset排序key
class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string,vector<string>> allStringSet;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            allStringSet[temp].push_back(strs[i]);
        }
        for(auto i=allStringSet.begin();i!=allStringSet.end();i++){
            result.push_back(i->second);
        }
        return result;
    }
};