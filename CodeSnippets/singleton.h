#include <mutex>

template<typename T>
class Singleton {
public:
    T& getSingleton() {
        if (instance == NULL) {
            lock.lock();
            if (instance == NULL) {
                instance = new T;
            }
            lock.unlock();
        }
        return *instance;
    }
private:
    Singleton() {}
    ~Singleton() {
        if(instance != NULL)
            delete instance;
    }
    //保证单例模式不可拷贝
    Singleton(const Singleton<T>& rhs) {}
    Singleton<T>& operator=(const Singleton<T>& rhs) {}
private:
    std::mutex lock;
    static volatile T* instance;
};

template<typename T>
volatile T* Singleton<T>::instance = NULL;
