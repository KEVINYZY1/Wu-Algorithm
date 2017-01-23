#ifndef KPSARAJU_H
#define KPSARAJU_H

#include<vector>
#include<set>
#include<queue>
using namespace std;

//无权有向图，判断有多少个强连通量
//输入的图，顶点是0到numVerteVx-1，然后pair类型的数组中，每个元素代表一条路径，second顶点指向first顶点
//kpsaraju算法
//步骤1，先获取有向图G的反向图G'的逆后序（逆后序也就是拓扑排序）；
//步骤2，对有向图G按照刚才得到的拓扑顺序进行DFS搜索；
//步骤3，所有在同一个Dfs函数中访问到的顶点属于同一个强连通分量。


class noWeightsDirectedGraph{
    public:
        noWeightsDirectedGraph(int numVerteVx, vector<pair<int, int>>& prerequisites)
        :graph_(numVerteVx), rGraph_(numVerteVx), in_(numVerteVx, 0){
            for(int i=0; i<prerequisites.size(); i++){
                graph_[prerequisites[i].second].insert(prerequisites[i].first);
                rGraph_[prerequisites[i].first].insert(prerequisites[i].second);
                ++in_[prerequisites[i].second];
            }
            topologicalSort(rGraph_);
        }

        vector<vector<int>> kpsaraju(){
            vector<vector<int>> result;
            vector<bool> visit(graph_.size(), false);
            int index=0;
            for(int i=0; i<topological_.size(); i++){
                if(!visit[i]){
                    result.push_back(vector<int>());
                    dfs(result, visit, i, index++);
                }
            }
            return result;
        }

    private:
        void dfs(vector<vector<int>> &result, vector<bool> &visit, int i, int index){
            if(visit[i])
                return;
            visit[i]=true;
            result[index].push_back();
            for(auto a : graph_[i]){
                if(!visit[a])
                    dfs(result,visit,a,index);
            }
        }

        void topologicalSort(vector<set<int> > graph){
            queue<int> q;
            for (int i = 0; i < graph.size(); ++i) {
                if (in[i] == 0) 
                    q.push(i);
            }
            while (!q.empty()) {
                int t = q.front();
                topological_.push_back(t);
                q.pop();
                for (auto a : graph[t]) {
                    --in[a];
                    if (in[a] == 0) 
                        q.push(a);
                }
            }
            //这里是检测有没有环的，我们默认输入的有向图无环
            for (int i = 0; i<numCourses; ++i) {
                if (in[i] != 0) 
                    return ;
            }
        }

        vector<set<int> > graph_;
        vector<set<int> > rGraph_;
        vector<int> topological_;
        vector<int> in_;//rGraph_每个顶点的入度
};


#endif