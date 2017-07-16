#include <deque>  
#include <pthread.h>
#include <functional>
#include <cassert>  


// 这是一个无边界的阻塞队列，这意味着它永远也不会满。
// 本质上，这个队列封装了生产者消费者问题，在本例中，我们只需要
// 一个Mutex来保证互斥，一个Condition来同步。当生产者放入产品时，
// 我们需要Condition帮助我们唤醒正在等待的消费者。
// 因为队列无边界，所以生产者不会阻塞，也不需要condition去唤醒他
// 所以只需要一个Condition

template<typename T>
class BlockingQueue {
    public:
        BlockingQueue() {
            pthread_mutex_init(&mutex_, NULL);
            pthread_cond_init(&condition_, NULL);
        }
        
        ~BlockingQueue() {
            pthread_mutex_destroy(&mutex_);
            pthread_cond_destroy(&condition_);
        }

        void put(const T& x) {
            pthread_mutex_lock(&mutex_);
            queue_.push_back(x);
            pthread_cond_signal(&condition_);// wait morphing saves us
            pthread_mutex_unlock(&mutex_);
        }

        T take() {
            pthread_mutex_lock(&mutex_);
            // always use a while-loop, due to spurious wakeup
            // 调用Condition的wait操作时，必须要上锁，而且必须采用while循环判断
            while (queue_.empty()) {
                pthread_cond_wait(&condition_, &mutex_);
            }
            assert(!queue_.empty());
        
            T front(queue_.front());
            queue_.pop_front();
            pthread_mutex_unlock(&mutex_);
            return front;
        }

        // 上面在判断队列是否为空时，不能使用下面的size函数，
        // 这样同一线程对同一个Mutex加锁两次，会造成死锁
        size_t size() {
            pthread_mutex_lock(&mutex_);
            int temp = queue_.size();
            pthread_mutex_unlock(&mutex_);
            return temp;
        }

    private:
        pthread_mutex_t mutex_;
        pthread_cond_t condition_;// 当生产者放入产品后，通知等待的消费者
        std::deque<T>     queue_;
};
