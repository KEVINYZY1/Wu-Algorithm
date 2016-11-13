#include<string>
using namespace std;

//查找接受. 代表任意字母
//内部实现一个字典树Tried树
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

class WordDictionary {
public:
    WordDictionary(){
        root = new TrieNode();
    }

    // Adds a word into the data structure.即字典树的插入
    void addWord(string word) {
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, root, 0);
    }
private:
    TrieNode* root;
    bool searchWord(string &word, TrieNode *p, int i) {
        if (i == word.size()) 
            return p->iskey;
        if (word[i] == '.') {
            for (auto &a : p->children) {
                if (a && searchWord(word, a, i+1)) 
                    return true;
            }
            return false;
        }
        else return p->children[word[i]-'a'] && searchWord(word, p->children[word[i]-'a'], i+1);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");