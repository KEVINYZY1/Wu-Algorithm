#ifndef INDEXPRIORITYQUEUE_H
#define INDEXPRIORITYQUEUE_H

//索引优先队列，相比于优先队列，可以利用索引更方便的控制队列的元素
//或者可以把索引优先队列看作是，一个可以快速访问其中最小元素的数组
#include<vector>
using namespace std;

#define indexPriorityQueue_SIZE 128
template<typename T>
class indexPriorityQueue{
    public:
        //索引的取值在0到size-1之间
        indexPriorityQueue(int size=indexPriorityQueue_SIZE)
        :pq_(size,0), key_(size), size_(0), pqReverseOrder_(size,-1){}

        //插入元素item，将item与索引key相关联
        void insert(int key, T item){
            size_++;
            pqReverseOrder_[key]=size_;
            pq_[size_]=key;
            key_[key]=item;
            swim(size_);
        }
        //将索引key的对应的元素改为item
        void charge(int key, T item){
            key_[key]=item;
            swim(pqReverseOrder_[key]);
            sink(pqReverseOrder_[key]);
        }
        //删除索引key及其相关联的元素
        void deleteKey(int key){
            int index=pqReverseOrder_[key];
            exch(index,size_--);
            swim(index);
            sink(index);
            pqReverseOrder_[key]=-1;
        }
        bool exist(int key){
            return pqReverseOrder_[key]!=-1;
        }

        //由于是优先队列，而且是按最小值维护的，故都是最小值相关的API
        //返回最小元素的值
        int min(){
            return key_[pq_[0]];
        }
        //返回最小元素的索引
        int minIndex(){
            return pq_[0];
        }
        //删除最小元素，并返回最小元素的索引
        int delMin(){
            int indexMin=pq_[0];
            exch(0,size_--);
            sink(0);
            pqReverseOrder_[pq_[size_+1]]=-1;
            return indexMin;
        }

        bool isEmpty(){
            return size_==0;
        }
        int size(){
            return size_;
        }
    private:
        void exch(int i, int j){//交换最小堆中第i和第j个的数对应的索引key
            int swap=pq_[i];
            pq_[i] = pq_[j];
            pq_[j] = swap;
            pqReverseOrder_[pq_[i]] = i;
            pqReverseOrder_[pq_[j]] = j;
        }

        bool less(int i, int j) {
            return key_[pq_[i]]<(key_[pq_[j]]);
        }

        void swim(int k) {
            while (k > 1 && less(k/2, k)) {
                exch(k, k/2);
                k = k/2;
            }
        }

        void sink(int k){
            while (2*k <= size_){
                int j = 2*k;
                if (j < size_ && less(j, j+1)) j++;
                if (!less(k, j)) break;
                exch(k, j);
                k = j;
            }
        }
        //下面两个数组，索引和值互相颠倒，只是为了更好的快速搜索
        //调整最小堆，也只调整下面两个数组
        vector<int> pq_;//下标是0到N-1，代表最小堆的下标
        vector<int> pqReverseOrder_;//下标是索引key
        
        vector<T> key_;//索引是key，值是item
        int size_;//记录已经插入元素的个数

};
#endif // ! INDEXPRIORITYQUEUE_H#