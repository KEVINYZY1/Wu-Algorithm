#include <pthread.h>
#include <functional>
#include <cassert> 

//主要是N个线程一起等

class CyclicBarrier {
    public:
        CyclicBarrier(int count) {
            count_ = count;
            pthread_mutex_init(&mutex_, NULL);
            pthread_cond_init(&condition_, NULL);
        }
        ~CyclicBarrier() {
            pthread_mutex_destroy(&mutex_);
            pthread_cond_destroy(&condition_); 
        }
        void wait() {
            pthread_mutex_lock(&mutex_);
            count_--;
            while (count_ > 0) {
               pthread_cond_wait(&condition_, &mutex_);
            }
            //这里解锁，因为pthread_cond_wait返回时候会自动获取锁
            pthread_mutex_unlock(&mutex_);
        }
    private:
        pthread_mutex_t mutex_;
        pthread_cond_t condition_;
        int count_;
};