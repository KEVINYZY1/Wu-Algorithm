#ifndef REGEX_MATCH_H
#define REGEX_MATCH_H

#include<vector>
#include<set>
#include<string>
#include<stack>
#include<assert>
#include"../Graph/GraphEdge.h"
using namespace std;

//正则表达式
//利用非确定有限状态自动机来实现
//根据输入的正则表达式，构造非确定性状态机。（正则表达式的每一个字符都是一个状态）
//非确定性状态机其实也就是一个有向图
//另外这只是正则最基本功能的实现，一些更琐碎的语法并没有支持。

//长度为m的正则表达式对应的状态机识别一个长度为n的文本，最坏情况下需要O(MN)时间
//正则表达式和NFA被证明是等价的：每一条正则表达式都对应等价的NFA（匹配相同的字符串），反之亦成立。
class NFA{
    public:
        NFA(string &regex):regex_(regex), graph_(regex.size()+1){
            size_=regex.size();
            stack<int>ops;//来处理正则表达式中的括号

            //开始处理输入的正则表达式
            for(int i=0; i<size_; i++){
                int lp=i;

                if(regex[i]=='(' || regex[i]=='|')
                    ops.push(i);
                else if(regex[i]==')'){
                    int or=ops.top();
                    ops.pop();
                    if(regex[or]=='|'){
                        lp=ops.top();
                        ops.pop();
                        graph_[lp].insert(directedEdge(lp, or+1, -1));
                        graph_[or].insert(directedEdge(or, i, -1));
                    }
                    else lp=or;
                }

                //闭包操作，这里即处理了 字符*情况 也处理了（）*的情况
                if(i<size_-1 && regex[i+1]=='*'){
                    graph_[lp].insert(directedEdge(lp, i+1, -1));
                    graph_[i+1].insert(directedEdge(i+1, lp, -1));
                }
                if(regex[i]=='(' || regex[i]=='*' || regex[i]==')')
                    graph_[i].insert(directedEdge(i, i+1, -1));
            }

            assert(ops.empty());
        }
        
        bool recongnizes(string &txt){
            DirectedDFS dfs(graph_, 0);//从0先开始dfs，有点疑问？？
            vector<int> pc;
            for (int v = 0; v < graph_.size(); v++)
                if (dfs.marked(v)) 
                    pc.push_back(v);

            for (int i = 0; i < txt.length(); i++) {
                assert(!(txt[i] == '*' || txt[i] == '|' || txt[i] == '(' || txt[i] == ')'));

                vector<int> match;
                for (int v : pc) {
                    if (v == size_) 
                        continue;
                    if ((regex_[v] == txt[i]) || regex_[v] == '.')
                        match.push_back(v+1); 
                }
                dfs = DirectedDFS(graph_, match); 
                pc.clear();
                for (int v = 0; v < graph_.size(); v++)
                    if (dfs.marked(v)) 
                        pc.push_back(v);

                if (pc.size() == 0) 
                    return false;
            }

            for (int v : pc)
                if (v == size_) return true;
            return false;
        }
    private:
        string regex_;
        int size_;//状态的数量
        vector<set<directedEdge> > graph_;//有向图，即我们要构造的状态机，有一个最终状态

        //辅助的dfs类
        class DirectedDFS{
            public:
                DirectedDFS(vector<set<directedEdge> >& graph, int s):marked_(graph.size(),false){
                    assert(s>=0 && s<graph.size());
                    dfs(graph, s);
                }

                bool marked(int v){
                    assert(v>=0 && v<graph.size());
                    return marked_[v];
                }
            private:
                int count_;
                vector<bool> marked_;
                void dfs(vector<set<directedEdge> >& graph, int v){
                    count_++;
                    marked_[v]=true;
                    for(auto s : graph[v]){
                        if(!marked_[v])
                            dfs(graph, s.w);
                    }
                }
        };
};

#endif