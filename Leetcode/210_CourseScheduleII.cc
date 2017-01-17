#include<vector>
#include<set>
#include<queue>
using namespace std;

//返回拓扑排序！！！
//类似于第一题的Bfs，把队列中的数都存起来，就是拓扑排序
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
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
        for (int i = 0; i<numCourses; ++i) {
            if (in[i] != 0) 
                return vector<int>();
        }
        return result;
    }
};