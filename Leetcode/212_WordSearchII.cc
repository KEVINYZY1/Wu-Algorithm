#include<vector>
#include<string>
#include<set>
using namespace std;

//You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
//第一题wordSearch，是在二维字符矩阵中，找到条路径是word
//现在这题，是给你一个字符串数组，然后确定矩阵中包含这个数组中的几个字符串。
//第一题使用Dfs即可
//第二题，即本题可使用字典树！！！
//也就是将字符串数组构造成字典树，然后进行dfs的时候，看看是否存在在字典树中。

//字典树实现
class TrieNode {
public:
    bool iskey;   // 标记该节点是否代表关键字
    TrieNode *children[26]; // 各个子节点
    TrieNode() {
        iskey = false;
        for(int i=0; i<26; ++i)
            children[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.不支持保存重复的
    void insert(string word) {
        auto tempRoot=root;
        for(int i=0; i<word.size(); i++){
            int num=word[i]-'a';
            if(tempRoot->children[num]==NULL){
                tempRoot->children[num]=new TrieNode();
            }
            tempRoot=tempRoot->children[num];
        }
        tempRoot->iskey=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto tempRoot=root;
        for(int i=0; i<word.size(); i++){
            int num=word[i]-'a';
            if(tempRoot->children[num]==NULL){
                return false;
            }
            tempRoot=tempRoot->children[num];
        }
        return tempRoot->iskey;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto tempRoot=root;
        for(int i=0; i<prefix.size(); i++){
            int num=prefix[i]-'a';
            if(tempRoot->children[num]==NULL){
                return false;
            }
            tempRoot=tempRoot->children[num];
        }
        return true;
    }
private:
    TrieNode* root;
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> s;
        vector<string> result;
        Trie t;
        for(int i=0; i<words.size(); i++){
            t.insert(words[i]);
        }
        if(board.empty())
            return result;
        rows_=board.size();
        columns_=board[0].size();
        vector<vector<bool>> visit(rows_, vector<bool>(columns_, false));
        for(int i=0; i<rows_; i++){
            for(int j=0; j<columns_; j++){
                dfs(board,s,visit,t,i,j,"");
            }
        }
        for(auto it=s.begin(); it!=s.end(); it++)
            result.push_back(*it);
        return result;
    }
private:
    void dfs(vector<vector<char>>& board, set<string>& s, vector<vector<bool>> &visit, Trie &t, 
                    int i, int j, string str){
        if(i<0 || i>=rows_ || j<0 ||j>=columns_)
            return;
        if(visit[i][j])
            return;
        str+=board[i][j];//str是dfs的前缀，如果前缀不在字典树中，则返回
        if(!t.startsWith(str))
            return;
        if(t.search(str))
            s.insert(str);
            
        visit[i][j]=true;
        dfs(board,s,visit,t,i+1,j,str);
        dfs(board,s,visit,t,i-1,j,str);
        dfs(board,s,visit,t,i,j+1,str);
        dfs(board,s,visit,t,i,j-1,str);
        visit[i][j]=false;
    }
    int rows_;
    int columns_;
};