#include <cstdlib>

template <typename T>
class shared_ptr {
public:
    shared_ptr()
        : count_(NULL), data_(NULL) {

        }
    explicit shared_ptr(T* data)
        : count_(new int(1)), data_(data) {

        }

    ~shared_ptr() {
        destory();
    }

    //拷贝构造函数
    shared_ptr(shared_ptr<T>& rhs) {
        *rhs.count_++;
        destory();
        data_ = rhs.date_;
        count_ = rhs.count_;
    }     
    //赋值运算符重载
    shared_ptr<T>& operator=(shared_ptr<T>& rhs) {
        *rhs.count_++;
        destory();
        data_ = rhs.date_;
        count_ = rhs.count_;
        return *this;
    }
    T* operator->() {
        return data_;
    }
    T& operator*() {
        return *data_;
    }
    //公共接口

private:
    void destory() {
        *count_--;
        if (*count_ == 0) {
            delete data_;
            delete count_;
        }
    }

private:
    int* count_; //引用计数
    T* data_; 
};