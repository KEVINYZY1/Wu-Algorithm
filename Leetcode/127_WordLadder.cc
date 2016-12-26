#include<string>
#include<queue>
#include<unordered_set>
using namespace std;

//假设输入符合要求
//bfs和dfs都可以寻找所有的可能排列，但这里，我们需要最短的。
//使用bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<string> Q;
        Q.push(beginWord); 
        Q.push("");//空字符串是层与层之间的分隔标志
        int res = 1;
        while(Q.empty() == false){
            string str = Q.front();
            Q.pop();
            if(str != ""){
                int strLen = str.length();
                for(int i = 0; i < strLen; i++){
                    char tmp = str[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == tmp)
                            continue;
                        str[i] = c;
                        if(str == endWord)
                            return res+1;
                        if(wordList.find(str) != wordList.end()){
                            Q.push(str);
                            wordList.erase(str);//如果要输出所有最短路径，则不能立即从字典中删除
                        }
                    }
                    str[i] = tmp;
                }
            }
            else if(Q.empty() == false){ //到达当前层的结尾，并且不是最后一层的结尾
                res++;
                Q.push("");
            }
        }
        return 0;
    }
};