#include <deque>  
#include <pthread.h>
#include <functional>
#include <cassert>  

class ThreadPool {
    public:
        typedef std::function<void()> Task;

    public:
        ThreadPool(int threadNum = 10) {
            threadsNum_ = threadNum;
            createThreads();
            isRunning_ = true;
        }

        ~ThreadPool() {
            stop();
        }

    public:
        size_t addTask(const Task& task) {
            pthread_mutex_lock(&mutex_);
            taskQueue_.push_back(task);
            int size = taskQueue_.size();
            pthread_mutex_unlock(&mutex_);
            pthread_cond_signal(&condition_);//提醒take函数的pthread_cond_wait处，告诉已经添加了一个任务，可以获取了
            /*印象笔记中条件变量内容
            pthread_cond_signal的作用跟pthread_cond_broadcast相似，但不同的是pthread_cond_signal会通知所有等待线程中的至少一个，让它（们）继续往下运行，而所有其它没被通知的等待线程则继续等待（休眠）。
            之所以pthread_cond_signal并不是严格地只唤醒一个等待线程，是因为在多处理器或多核系统中，强制实现只唤醒一个等待线程可能不太容易。
            另外，pthread_cond_wait本身也会存在”虚假唤醒“的情况。也就是即便没有任何其它线程调用pthread_cond_signal或pthread_cond_broadcast，pthread_cond_wait也可能因为各种原因自动返回，比如说被信号中断。
            但实际应用场景中我们通常希望每调用一次pthread_cond_signal就唤醒一个等待线程，比如说下面这种情况：
            某个线程专门负责从网络接收数据包，其它若干线程专门负责处理数据包。当没有任何数据包时，处理线程全部调用pthread_cond_wait陷入等待。
            当一个数据包到达时，接收线程调用phtread_cond_signal唤醒一个处理线程，处理线程拿走这个数据包去处理。
            当又一个数据包到达时，接收线程再次调用pthread_cond_signal唤醒一个线程
            */
            return size;
        }

        void stop() {
            if (!isRunning_) {
                return;
            }

            isRunning_ = false;
            pthread_cond_broadcast(&condition_);

            for (int i = 0; i < threadsNum_; i++) {
                pthread_join(threads_[i], NULL);
            }

            free(threads_);
            threads_ = NULL;

            pthread_mutex_destroy(&mutex_);
            pthread_cond_destroy(&condition_);
        }

        int size() {
            pthread_mutex_lock(&mutex_);
            int size = taskQueue_.size();
            pthread_mutex_unlock(&mutex_);
            return size;
        }

        Task take() {
            Task task = NULL;
            pthread_mutex_lock(&mutex_);
            while (taskQueue_.empty() && isRunning_) {
                pthread_cond_wait(&condition_, &mutex_);//会虚假唤醒
                /*
                那就是前面一直没提的pthread_cond_wait的第二个参数了。
                看看本文最开始列出的函数声明，第二个参数赫然是mutex！
                这下猜也能猜到这第二个参数是干嘛的了，明显就是专门帮我们解开mutex锁啊，然后在pthread_cond_wait返回之前再自动获取mutex锁。
                如果不解锁，那么在任务列表空的时候，工作线程等待中，然而生产任务的线程无法获得锁，这样会发生死锁。
                这里顺道澄清一下，和条件变量关联的mutex，不是像网上部分人说的那样是用来保护条件变量的，条件变量在实现的时候是能够做到线程安全的，因为它内部还有一个自己的互斥锁。
                */
            }
            
            if (!isRunning_) {
                pthread_mutex_unlock(&mutex_);  
                return task;
            }

            assert(!taskQueue_.empty());
            task = taskQueue_.front();
            taskQueue_.pop_front();
            pthread_mutex_unlock(&mutex_);
            return task;
        }

    private:
        int createThreads() {
            pthread_mutex_init(&mutex_, NULL);
            pthread_cond_init(&condition_, NULL);
            threads_ = (pthread_t*)malloc(sizeof(pthread_t) * threadsNum_);
            for (int i = 0; i < threadsNum_; i++) {
                pthread_create(&threads_[i], NULL, threadFunc, this);
            }
            return 0;
        }

        static void* threadFunc(void * arg) {
            pthread_t tid = pthread_self();
            ThreadPool* pool = static_cast<ThreadPool*>(arg);
            while (pool->isRunning_) {
                ThreadPool::Task task = pool->take();
                if (!task) {
                    printf("thread %lu will exit\n", tid);
                    break;
                }

                assert(task);
                task();
            }
            return 0;
        }

    private:
        ThreadPool& operator=(const ThreadPool&);
        ThreadPool(const ThreadPool&);

    private:
        volatile  bool              isRunning_;
        int                         threadsNum_;
        pthread_t*                  threads_;

        std::deque<Task>            taskQueue_;
        pthread_mutex_t             mutex_;
        pthread_cond_t              condition_;
};

