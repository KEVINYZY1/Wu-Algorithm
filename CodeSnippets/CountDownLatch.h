#include <deque>  
#include <pthread.h>
#include <functional>
#include <cassert>  

class CountDownLatch {
    public:

        explicit CountDownLatch(int count) {
            count_ = count;
            pthread_mutex_init(&mutex_, NULL);
            pthread_cond_init(&condition_, NULL);
        }

        ~CountDownLatch() {
            pthread_mutex_destroy(&mutex_);
            pthread_cond_destroy(&condition_);
        }

        void wait() {
            pthread_mutex_lock(&mutex_);
            while (count_ > 0) {
               pthread_cond_wait(&condition_, &mutex_);
            }
            //这里解锁，因为pthread_cond_wait返回时候会自动获取锁
            pthread_mutex_unlock(&mutex_);
        }

        void countDown() {
            pthread_mutex_lock(&mutex_);
            count_--;
            if (count_ == 0) {
                pthread_cond_broadcast(&condition_);
            }
            pthread_mutex_unlock(&mutex_);
        }

        int getCount() {
            pthread_mutex_lock(&mutex_);
            int temp = count_;
            pthread_mutex_unlock(&mutex_);
            return count_;
        }

    private:
        pthread_mutex_t mutex_;
        pthread_cond_t condition_;
        int count_;
};