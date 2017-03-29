#ifndef TRIE_H
#define TRIE_H
#include<string>
using namespace std;
//实现一个Trie树！！
//用空间换取时间的方法
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
    
    // 向字典树中插入字符串，不支持保存重复的
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

    // 字典树中是否有该字符串
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

    //看字典树中是否含有该前缀的字符串
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

    //返回字典树中与query有着最长前缀的字符串
    string longestPrefixof(string query){
        string result;
        if(query.empty())
            return result;
        auto node=root;
        int i=0;
        const int len=query.size();
        while(node!=NULL){
            if(i>=len)
                return query;
            if(node->children[query[i]-'a']!=NULL){
                node=node->children[query[i]-'a'];
                i++;
            }
            else break;
        }
        return query.substr(0,i);
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


//左孩子右兄弟也可以

#endif