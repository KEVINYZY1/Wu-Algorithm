#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#include<vector>
#include<string>
using namespace std;

//RabinKarp算法
//基于哈希，即对模式串进行哈希运算并将其哈希值与文本中子串的哈希值进行比对
//该算法的关键，在于可以在常数时间计算出每一个子字符串的哈希值！！
    //Rm很重要，
//Rabin-Karp的复杂度理论上是O(nm)，但在实际使用中通常是O(n+m)。
//Rabin-Karp算法非常适用于多模式匹配，比如它可以用来检测抄袭（可以计算出多个要被匹配的字符串的hash值，来比较）
//如果能够选择一个好的哈希函数，它的效率将会很高，而且也易于实现

//在最后找出一致的哈希值之后，有两种办法确定我们是不是找对了
//蒙特卡洛法，将散列的规模设为相当大（因为我们并不需要保存所有散列数，所以散列表再大也不影响。）
    //这样哈希值冲突的情况会特别小（是哈希表长度分之一的几率碰撞），再者也可以重复运行两次来保证(这要求哈希表大小值是随机取的)。
//拉斯维加斯法，即验证一遍找到的字符串和被匹配的字符串。这样面对流输入的情况，会比较蛋疼。


static int SIZEALPH=256;   //字母表的大小

class RabinKarp{
    public:
        RabinKarp(string& pat):pat_(pat){
            sizePat_=pat.size();
            Q=4294967291ul;
            Rm=1;
            for (int i = 1; i <= sizePat_-1; i++)
                Rm = (SIZEALPH * Rm) % Q;
            patHash_=hash(pat_, sizePat_);
        }

        //哈希函数，SIZEALPH进制的size位数作为hash值
        long hash(string &key, int size) { 
            long h = 0; 
            for (int j = 0; j < size; j++) 
                h = (SIZEALPH*h + key[j]) % Q;
            return h;
        }

        //拉斯维加斯法
        bool check(string txt, int i) {
                for (int j = 0; j < sizePat_; j++) 
                    if (pat_[j] != txt[i + j]) 
                        return false; 
                return true;
            }


        int search(string txt) {
            int n = txt.size(); 
            if (n < sizePat_) return n;
            long txtHash = hash(txt, sizePat_); 

            //如果第一发就命中
            if ((patHash_ == txtHash) && check(txt, 0))
                return 0;

            for (int i = sizePat_; i < n; i++) {
                //关键，高效的求出右移一位之后字符串的哈希值！！
                txtHash = (txtHash + Q - Rm*txt[i-sizePat_] % Q) % Q; 
                txtHash = (txtHash*SIZEALPH + txt[i]) % Q; 

                int offset = i - sizePat_ + 1;
                if ((patHash_ == txtHash) && check(txt, offset))
                    return offset;
            }

            return -1;
        }

    private:
        string pat_; 
        long patHash_;//模式字符串的哈希值
        int sizePat_;
        long Q;//散列表的大小，很大的素数
        long Rm;//SIZEALPH * ( sizePat_ - 1 ) % Q

};
#endif