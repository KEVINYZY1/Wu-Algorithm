/*
输入
N
然后是N行， 每行两个string，分别代表函数调用关系
最后一行，给出两个函数，问是不是调用关系

把有向图构造出来，然后深度遍历一遍就知道是不是连通了
*/

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct node {
    string function;
    vector<node*> v;
};

int main() {
    int N;
    while (cin >> N) {
        map<string, node*> m;
        set<string> s;
        for (int i =0 ; i < N; i++) {
            string temp1, temp2;
            cin >> temp1 >> temp2;
            if(s.find(temp1) == s.end()) {
                m[temp1] = new node;
                m[temp1]->function = temp1;
                s.insert(temp1);
            }
            if(s.find(temp2) == s.end()) {
                m[temp2] = new node;
                m[temp2]->function = temp2;
                s.insert(temp2);
            }
            m[temp1]->v.push_back(m[temp2]);//会重复
        }
        string A, B;
        cin >> A >> B;
        auto nodeA = m[A];
        auto nodeB = m[B];
        map<string, bool> search;
        for (auto item : m) {
            search[item.first] = false;
        }
        queue<node*> q;
        q.push(nodeA);
        search[A] = true;
        bool isCall = false;
        while (!q.empty()) {
            auto n = q.front();
            q.pop();
            for (auto item : n->v) {
                if (item == nodeB){
                    isCall = true;
                    break; // 除了goto，还有什么跳出深嵌套的好办法
                } else {
                    if (!search[item->function]) {
                        q.push(item);
                        search[item->function] = true;
                    }
                }
            }
        }
        if (isCall)
            cout << "T" << endl;
        else cout << "F" << endl;
    }
}