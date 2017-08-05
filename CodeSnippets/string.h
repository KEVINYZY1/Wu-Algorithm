#include <utility>
#include <string.h>
 
class String {
public:
    String()
        : data_(new char[1]) {
        *data_ = '\0';
    }
    
    /* 没考虑str为NULL
    String(const char* str)
        : data_(new char[strlen(str) + 1]) {
        strcpy(data_, str);
    }
    */
    String(const char *str) {
        if (str == NULL) {
            data_ = new char[1];
            data_[0] = '\0'; 
        } else {
            data_ = new char[strlen(str) + 1];
            strcpy(data_, str);
        }
    }

    //拷贝构造函数
    String(const String& rhs)
        : data_(new char[rhs.size() + 1]) {
        strcpy(data_, rhs.c_str());
    }
    /* Delegate constructor in C++11
    String(const String& rhs)
        : String(rhs.data_)
    {
    }
    */
    
    ~String() {
        delete[] data_;
    }
    
    /* Traditional:
    String& operator=(const String& rhs)
    {
        这样做的好处，是可以保证异常安全性
        String tmp(rhs);
        swap(tmp);
        return *this;
    }
    */
    String& operator=(String rhs) {//传值，这样rhs就是全新的拷贝
        swap(rhs);//这里有个技巧，不用担心原来的date_成员的内存泄漏，rhs销毁的时候，自动删除date_成员
        return *this;
    }

    String& operator+(const String& rhs) {
        String newStr;
        //释放原有空间
        delete[] newStr.data_;
        newStr.data_ = new char[strlen(data_) + strlen(rhs.data_) + 1];
        strcpy(newStr.data_, data_);
        strcpy(newStr.data_ + strlen(data_), rhs.data_);
        swap(newStr);//这里有个技巧，不用担心原来的date_成员的内存泄漏
        return *this;
    }

    char& operator[](int e) {  
        if (e >= 0 && e <= strlen(data_))  
            return data_[e];  
    }
    
    bool operator==(const String &s) { 
        return strcmp(data_, s.data_) ? false : true;  
    }    
    
    // C++ 11
    String(String&& rhs)
        : data_(rhs.data_) {
        rhs.data_ = nullptr;
    }
    
    String& operator=(String&& rhs) {
        swap(rhs);
        return *this;
    }
    
    // Accessors
    size_t size() const {
        return strlen(data_);
    }
    
    const char* c_str() const {
        return data_;
    }
    
    void swap(String& rhs) {
        std::swap(data_, rhs.data_);
    }
    
private:
    char* data_;//要求末尾'\0'结尾
};
