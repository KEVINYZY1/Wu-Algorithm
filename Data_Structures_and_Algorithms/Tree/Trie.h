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

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


//左孩子右兄弟也可以

#endif