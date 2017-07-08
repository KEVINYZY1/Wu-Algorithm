//虚继承

//sizeof(animal) == 24
//对于c++对象的成员函数，不管是静态还是非静态的，都是把它们存放在类对象之外
//可以作为全局函数来看待，编译时期就确定调用
//而数据成员，都是存放在每个类对象中单独拥有的
//对于虚函数来说，则存放虚函数表的指针，指针的设定由构造析构函数自动完成
//一个虚函数表指针就足够了！！
class animal{
    public:
        animal(){}
        ~animal(){}
        char name[10];//动物名字
        int weight;//体重
        virtual void eat(){};//动物都需要吃，所以将eat设为虚函数，方便后面继承
        virtual void sleep(){};//同上
    private:

};

//sizeof(dog) == 32
//多了个虚函数，也只是修改下虚函数指针所指向的虚函数表
class dog: public animal{
    public:
        int breed;
        void eat()override{};
        virtual void yelp() {};//新开一个虚函数
    private:
    
};

class canidae{
    public:
        int age;
        virtual void eat(){};
        virtual void yelp() {};//新开一个虚函数
    private:
    
};

//多重继承
//这时候会有两个虚函数指针，分别给两个父类
class dogcan: public animal, public canidae{
    public:
        int breed;
        void eat()override{};
        virtual void yelp() {};//新开一个虚函数
    private:
    
};

//这里可以加上虚拟继承！
class live: public animal{
    public:
        int color;
        virtual void eat(){};
        virtual void watch() {};//新开一个虚函数
    private:
    
};

//多重继承，有公共祖先类的情况
class doglive: public animal, public live{
    public:
        int breed;
        void eat()override{};
        virtual void yelp() {}; //新开一个虚函数
    private:
    
};