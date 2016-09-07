#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H 
#include <vector>
using namespace std;
//用最小堆实现一个最小优先队列

template<class T>
class priorityqueue{
public:
    //将元素x插入最小堆s中
    void insertElement(vector<T> &s,T x);
    //返回最小堆中的最小元素
    T minElement (vector<T>s);
    //返回最小堆中的最小元素，并且在堆中删除该元素
    T extractMinElement(vector<T> &s);
    //将集合中下标为index元素的权值减少到k，假设k小于该元素原来的权值
    void decreaseKey(vector<T> &s,int index,T k);
private:
    vector<T> s;
    int parent(int index){
        if(index&1){
            return index/2;
        }
        else return index/2-1;
    }
    int leftChild(int index){
        return 2*index+1;
    }
    int rightChild(int index){
        return 2*index+2;   
    }
    //维持最小堆
    void minHeapFix(vector<T>&s,int index){
        int smallest=index;
        if(leftChild(index)<s.size()&&s[leftChild(index)]<s[index]){
            smallest=leftChild(index);
        }
        if(rightChild(index)<s.size()&&s[rightChild(index)]<s[smallest]){
            smallest=rightChild(index);
        }
        if(smallest!=index){
            swap(s[index],s[smallest]);
            minHeadpFix(s,smallest);
        }
    }
};

template<class T>
void priorityqueue<T>::insertElement (vector<T>&s,T x){
    s.push_back(x);
    decreaseKey(s,s.size()-1,x);
}
template<class T>
void priorityqueue<T>::decreaseKey (vector<T>&s,int index, T k){
    assert(k<=s[index]);
    s[index]=k;
    while(index>0 && s[parent(index)]>s[index]){
        swap(s[index],s[parent(index)]);
        index=parent(index);
    }
}
template<class T>
T priorityqueue<T>::minElement (vector<T>s){
    assert(!s.empty);
    return s[0];
}
template<class T>
T priorityqueue<T>::extractMinElement (vector<T>&s){
    assert(!s.empty);
    T result=s[0];
    swap(s[0],s[s.size()-1]);
    s.pop_back();
    minHeapFix(s,0);
    return result;
}
#endif