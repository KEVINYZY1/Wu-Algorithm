//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

//从n的2进制形式的最右边开始判断是不是1
/*
    * 该解法如果输入时负数会陷入死循环，
    * 因为负数右移时，在最高位补得是1
    * 二本题最终目的是求1的个数，那么会有无数个
    * 1了。
    */
class Solution {
public:
    int NumberOf1(int n) {
        int count = 0;
        while (n) {
            n = (n - 1) & n;
            count++;
        }
        return count;
    }
};