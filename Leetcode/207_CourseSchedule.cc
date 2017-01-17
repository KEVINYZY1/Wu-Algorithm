#include<vector>
#include<set>
#include<queue>
using namespace std;

//类似于有优先级的任务调度
//有向无环图，因为有环就无法完成了
//判断给的有向图，是否存在环，如果存在环，那么就无法拓扑排序
//拓扑排序！！！

//方法1，BFS
class Solution1 {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);//顶点是索引，值是入度
        vector<set<int>> graph(numCourses);//顶点是索引
        for(auto it=prerequisites.begin();it!=prerequisites.end();it++){
            inDegree[it->first]++;
            graph[it->second].insert(it->first);
        }
        queue<int> qZeroInDegree;//存放所有入度为0的顶点
        
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0)
                qZeroInDegree.push(i);
        }
        //开始对入度为0的顶点开始BFS
        while(!qZeroInDegree.empty()){
            int node=qZeroInDegree.front();
            qZeroInDegree.pop();
            for(auto it=graph[node].begin();it!=graph[node].end();it++){
                //减少入度，若入度等于0，则再加入到队列中去。
                inDegree[*it]--;
                if(inDegree[*it]==0)
                    qZeroInDegree.push(*it);
            }
        }
        for(auto it=inDegree.begin();it!=inDegree.end();it++){
            if(*it!=0)
                return false;
        }
        return true;
    }
};


//方法2，DFS
class Solution2 {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<set<int> > graph(numCourses);
        vector<int> visit(numCourses,0);//这里visit不能单纯用bool，会超时

        for(auto it=prerequisites.begin();it!=prerequisites.end();it++)
            graph[it->second].insert(it->first);
        for(int i=0;i<numCourses;i++){
            if(!dfs(graph,visit,i))
                return false;
        }
        return true;
    }
private:
    bool dfs(vector<set<int> > &graph, vector<int> &visit, int i){
        //visit等于1的时候表示从这个点出发的图不会存在环
        //visit等于-1的时候表示正在检查这个点，如果回到了有-1的顶点，那么就肯定有环
        if(visit[i]==-1)
            return false;
        if(visit[i]==1)
            return true;
        visit[i]=-1;
        for(auto it=graph[i].begin();it!=graph[i].end();it++){
            if(!dfs(graph,visit,*it))
                return false;
        }
        visit[i]=1;
        return true;
    }
};