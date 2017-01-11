#ifdef INDEXPRIORITYQUEUE_H
#define INDEXPRIORITYQUEUE_H

//索引优先队列，相比于优先队列，可以利用索引更方便的控制队列的元素
//或者可以把索引优先队列看作是，一个可以快速访问其中最小元素的数组
#include<vector>
using namespace std;

#define indexPriorityQueue_SIZE 128
class indexPriorityQueue{
    public:
        //索引的取值在0到size-1之间
        indexPriorityQueue(int size=indexPriorityQueue_SIZE){
            size_=0;//开始设为0
            for (size_t i = 0; i < indexPriorityQueue_SIZE; i++){
                pq_.push_back(0);
                key_.push_back(0);
                pqReverseOrder_.push_back(-1);
            }
        }

        //插入元素item，将item与索引key相关联
        void insert(int key, int item){
            size_++;
            pqReverseOrder_[key]=size_;
            pq_[size_]=key;
            key_[key]=item;
            swim(size_);
        }
        //将索引key的对应的元素改为item
        void charge(int key, int item){
            key_[key]=item;
            swim(pqReverseOrder_[key]);
            sink(pqReverseOrder_[key]);
        }
        //删除索引key及其相关联的元素
        void delete(int key){
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
            while (2*k <= n){
                int j = 2*k;
                if (j < n && less(j, j+1)) j++;
                if (!less(k, j)) break;
                exch(k, j);
                k = j;
            }
        }

        vector<int> pq_;//下标是0到N-1，代表最小堆的下标
        vector<int> pqReverseOrder_;//下标是索引key
        vector<int> key_;//下标是索引key
        int size_;//记录已经插入元素的个数

};
#endif // ! INDEXPRIORITYQUEUE_H#