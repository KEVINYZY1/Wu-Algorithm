#include <memory>
#include <vector>
#include <pthread.h>

using namespace std;

class Observable;

class Observer : public enable_shared_from_this<Observer> {
public:
    Observer(Observable* s); 
    ~Observer() {
        
    }


    void update() {
        //别循环调用Observable的mutex，不可重入的
    }
private:
    shared_ptr<Observable> subject_;
};

class Observable {
public:
    Observable() {
        pthread_mutex_init(&mutex_, NULL);
    }
    ~Observable() {
        pthread_mutex_destroy(&mutex_);
    }

    //观察者Observer注册到被观察者上
    void registerObserver(weak_ptr<Observer> x) {
        pthread_mutex_lock(&mutex_);
        observers_.push_back(x);
        pthread_mutex_unlock(&mutex_);
    }

    /*不再需要unregisterObserver函数，因为已经在notifyObservers里面实现了*/

    //被观察者有变化，通知所有观察者
    void notifyObservers() {
        pthread_mutex_lock(&mutex_);
        auto it = observers_.begin();
        while (it != observers_.end()) {
            shared_ptr<Observer> obj(it->lock());
            if (obj != nullptr) {
                obj->update();
                it++;
            } else {
                it = observers_.erase(it);
            }
        }
        pthread_mutex_unlock(&mutex_);
    }

private:
    vector<weak_ptr<Observer> > observers_;
    mutable pthread_mutex_t mutex_;
};

Observer::Observer(Observable* s) : subject_(s){
    subject_->registerObserver(shared_from_this());
}
