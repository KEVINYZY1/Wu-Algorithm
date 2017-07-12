#ifndef  TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include<vector>
#include<set>
#include<queue>
#include<list>
using namespace std;
//求一个有向无权图的拓扑排序
//如果该图存在环，则不存在拓扑排序
//输入的图，顶点是0到numVerteVx-1，然后pair类型的数组中，每个元素代表一条路径，second顶点指向first顶点

class topologicalSort {
public:
    //bfs
    //构建入度为0的队列，然后不断的对队列操作
    vector<int> findOrder(int numVerteVx, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        vector<vector<int> > graph(numVerteVx, vector<int>(0));
        vector<int> in(numVerteVx, 0);
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        queue<int> q;
        for (int i = 0; i < numVerteVx; ++i) {
            if (in[i] == 0) 
                q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            result.push_back(t);
            q.pop();
            for (auto a : graph[t]) {
                --in[a];
                if (in[a] == 0) 
                    q.push(a);
            }
        }
        for (int i = 0; i < numVerteVx; ++i) {
            if (in[i] != 0) 
                return vector<int>();
        }
        return result;
    }
    //Dfs
    //遍历顶点，不断判断顶点是否含有环，在没环的情况下，把节点插入头部
    vector<int> findOrder2(int numVerteVx, vector<pair<int, int>>& prerequisites) {  
        vector<list<int>> adj(numVerteVx, list<int>());  
        vector<bool> visited(numVerteVx, false);  
        vector<bool> onstack(numVerteVx, false);  
        vector<int> order;  
        
        for (auto& it : prerequisites) {  
            adj[it.second].push_back(it.first);  
        }  
        
        for (int i = 0; i < numVerteVx; ++i) {  
            if (visited[i]) 
                continue;  
            if (hasCycle(adj, i, visited, onstack, order)) 
                return vector<int>();  
        }  
        return order;  
    }  
    
    bool hasCycle(vector<list<int>>& adj, int v, vector<bool>& visited, vector<bool>& onstack, vector<int>& order) {  
        visited[v] = true;  
        onstack[v] = true;  
        for (auto& it : adj[v]) {  
            if (!visited[it] && hasCycle(adj, it, visited, onstack, order)) 
                return true;  
            if (onstack[it]) 
                return true;  
        }  
        order.insert(order.begin(), v);  
        onstack[v] = false;  
        return false;  
    } 

};

#endif