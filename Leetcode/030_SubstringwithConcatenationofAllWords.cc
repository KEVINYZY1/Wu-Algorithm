#include<vector>
#include<multiset>
#include<unordered_map>
using namespace std;

//从字符串寻找子字符串的加强版
//最笨的方法，穷举words可能排列，然后一个个查找
//超时！！！
class Solution1{ 
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>result;
        if(words.empty()){
            return result;
        }
        int wordSize=words[0].size();
        multiset<string>wordSet(words.begin(),words.end());
        multiset<string>temp;
        for(int i=0;i<s.size();i++){
            if(i+words.size()*wordSize>s.size())
                break;
            if(wordSet.find(s.substr(i,wordSize))!=wordSet.end()){
                temp.insert(s.substr(i,wordSize));
                int j=1;
                while(j<words.size()){
                    if(wordSet.find(s.substr(i+j*wordSize,wordSize))!=wordSet.end()){
                        temp.insert(s.substr(i+j*wordSize,wordSize));
                        j++;
                    }
                    else break;
                }
                if(j==words.size() && mismatch(wordSet.begin(),wordSet.end(),temp.begin()).first==wordSet.end())
                    result.push_back(i);
                temp.clear();
            }
        }
        return result;
    }
};

//为了效率，使用哈希，哈希由于无序，不方便使用mismatch算法比较，这时使用string与int关联，来应对有重复word的情况
class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.size()==0) {
            return result;
        }
        
        unordered_map<string, int> hash;
        for (int i=0; i < words.size(); i++) {
            if (hash.find(words[i]) == hash.end()) {
                hash[words[i]]=1;
            } else {
                hash[words[i]]++;
            }
        }
        
        int wSize = words[0].length();
        for (int start=0; start < wSize; start++) {
            int wCount=0;
            unordered_map<string, int> slidingWindow;
            for (int i=start; i+wSize<=s.length(); i+=wSize) {
                string word = s.substr(i, wSize);
                if (hash.find(word) == hash.end()) {
                    slidingWindow.clear();
                    wCount = 0;
                } else {
                    wCount++;
                    if (slidingWindow.find(word) == slidingWindow.end()) {
                        slidingWindow[word]=1;
                    } else {
                        slidingWindow[word]++;
                    }
                    while (hash[word] < slidingWindow[word]) {
                        string removedWord = s.substr(i-(wCount-1)*wSize, wSize);
                        slidingWindow[removedWord]--;
                        wCount--;
                    }
                }
                
                if (wCount == words.size()) {
                    result.push_back(i-(wCount-1)*wSize);
                }
            }
        }
        return result;
    }
};