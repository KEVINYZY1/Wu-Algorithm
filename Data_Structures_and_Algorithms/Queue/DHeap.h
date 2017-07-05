//d叉堆有与二叉堆很类似，但（一个可能的例外是）其中的每个非叶结点有d个子女，而不是2个。
//当d>2的时候，d叉堆的优势是简化了插入操作，因为d叉堆深度比二叉堆深度浅的多。然而d叉堆的删除操作却复杂化了。
//当优先队列太大不能完全装入内存的时候，d-堆也是很有用的，在这种情况下，d-堆能够以与B-树大致相同的方式发挥作用。
#ifndef D_ARYHEAP_H
#define D_ARYHEAP_H
#include <vector>
using namespace std;

//构建的是最小优先队列。
template<class T>
class DHeap {
public:
    //默认构造函数，默认为三叉堆
    DHeap() : d(3) {}
    //由用户确定d叉堆中d的取值
    DHeap(int value) : d(value) {}
    //将元素x插入最小堆s中
    void insertElement(vector<T>& s, T x);
    //返回最小堆中的最小元素
    T minElement (vector<T>s);
    //返回最小堆中的最小元素，并且在堆中删除该元素
    T extractMinElement(vector<T> &s);
    //将集合中下标为index元素的权值减少到k，假设k小于该元素原来的权值
    void decreaseKey(vector<T>& s, int index, T k);
private:
    vector<T> s;
    int d;
    int parent(int index) {
        return (index - 1) / d;
    }
    //只有这里调整步骤需要修改
    void minHeapFix(vector<T>& s, int index) {
        int childIndex = index * d + 1;
        int smallest = index;
        for (int i = childIndex; i < childIndex + d; i++) {
            if (s[i] < s[smallest])
                smallest = i;
        }
        if (smallest != index) {
            swap(s[smallest], s[index]);
            minHeapFix(s, smallest);
        }
    } 
}; 

template<class T>
void DHeap<T>::insertElement(vector<T>& s, T x) {
    s.push_back(x);
    decreaseKey(s, s.size() - 1, x);
}
template<class T>
void DHeap<T>::decreaseKey (vector<T>& s, int index, T k) {
    assert(k <= s[index]);
    s[index] = k;
    while (index > 0 && s[parent(index)] > s[index]) {
        swap(s[index], s[parent(index)]);
        index = parent(index);
    }
}
template<class T>
T DHeap<T>::minElement (vector<T> s) {
    assert(!s.empty());
    return s[0];
}
template<class T>
T DHeap<T>::extractMinElement (vector<T>& s) { 
    assert(!s.empty());
    T result = s[0];
    swap(s[0], s[s.size() - 1]);
    s.pop_back();
    minHeapFix(s, 0);
    return result;
}

#endif