#include<unordered_map>
#include<list>
using namespace std;

//LRU是Least Recently Used的缩写，意思是最近最少使用，它是一种Cache替换算法。
//LRU的典型实现是hash map + doubly linked list
//双向链表用于存储数据结点，并且它是按照结点最近被使用的时间来存储的。 
//哈希表用来保证O(1)时间访问到链表的任一结点。
struct CacheNode{
    int key;
    int value;
    CacheNode(int k , int v) : key(k) , value(v){}
};
class LRUCache{
public:
    LRUCache(int capacity) {//构造函数
        size=capacity;
    }
    
    int get(int key) {
        auto temp=m.find(key);
        if(temp==m.end())
            return -1;
        else {
            l.splice(l.begin(),l,temp->second);//链表容器的操作
            m[key]=l.begin();
            return l.begin()->value;
        }
    }
    
    void set(int key, int value) {
        if(m.find(key)==m.end()){
            if(l.size()==size){
                m.erase(l.back().key);
                l.pop_back();
            }
            l.push_front(CacheNode(key,value));
            m[key]=l.begin();
        }
        else{
            m[key]->value=value;
            l.splice(l.begin(),l,m[key]);
            m[key]=l.begin();
        }
    }
private:
    int size;
    list<CacheNode> l;
    unordered_map<int,list<CacheNode>::iterator>m;
};