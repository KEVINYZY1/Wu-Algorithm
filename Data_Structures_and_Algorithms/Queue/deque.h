#ifndef DEQUE_H
#define DEQUE_H
#include<array>
#include<cstdlib>
#define ARRAY_SIZE 1024
//在数组的基础上，实现deque，双向队列
class deque{
    public:    
        deque(){
            head = tail = 512;
        }
        bool enDequeFront(int a) {
            if (head > 0 && head - 1 != tail) {
                arrayDeque[head - 1] = a;
                head--;
            } else if (head == 0) {
                if (tail != 1023)
                    head = 1023;
                else return false;
                arrayDeque[0] = a;
            }
            return true;
        }
        bool deDequeFront() {
            if (head == tail) {
                return false;
            }
            head++;
            return true;
        }
        bool enDequeEnd(int a) {
            if (tail < 1023 && tail + 1 != head) {
                arrayDeque[tail] = a;
                tail++;
            } else if (tail == 1023) {
                if (head != 0)
                    tail = 0;
                else return false;
                arrayDeque[1023] = a;    
            }
            return true;
        }
        bool deDequeEnd() {
            if (head == tail) {
                return false;
            }
            tail--;
            return true;
        }
        
    private:
        std::array <int, ARRAY_SIZE> arrayDeque;
        size_t head;
        size_t tail;
        //head和tail下标维护左开右闭区间
};
#endif