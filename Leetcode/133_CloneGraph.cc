#include<vector>
#include<queue>
#include<map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

//图的复制
//Bfs
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)
            return NULL;  
         
        map<int, UndirectedGraphNode*> nodes;//利用label快速定位图的节点  
        queue<UndirectedGraphNode*> q;  
          
        q.push(node);  
          
        while(!q.empty()){  
            UndirectedGraphNode* tmp = q.front();  
            q.pop();  
            if(nodes.find(tmp->label)==nodes.end()){  
                UndirectedGraphNode* new_node = new UndirectedGraphNode(tmp->label);  
                nodes.insert(pair<int, UndirectedGraphNode*>(new_node->label, new_node));  
                for(int i=0;i<tmp->neighbors.size();i++){  
                    q.push(tmp->neighbors[i]);
                }  
            }  
        }  
          
        q.push(node);  
        //必须再bfs一遍，因为第一遍没有把所有节点都创建起来，无法填充neighbors
        while(!q.empty()){  
            UndirectedGraphNode* tmp = q.front();  
            q.pop();  
            UndirectedGraphNode* existingnode = nodes[tmp->label];  
            if(existingnode->neighbors.empty()&&!tmp->neighbors.empty()){  
                for(int i=0;i<tmp->neighbors.size();i++){  
                    existingnode->neighbors.push_back(nodes[tmp->neighbors[i]->label]);  
                    q.push(tmp->neighbors[i]);  
                }  
            }  
        }  
          
        return nodes[node->label];  
    }
};