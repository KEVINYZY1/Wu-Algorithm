//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。

class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0)
            return 0;
        else if (n == 1 || n == 2)
            return 1;
        n -= 2;
		int prev = 1;
        int cur = 1;
        while (n > 0) {
            n--;
            int temp = cur;
            cur += prev;
            prev = temp;
        }
        return cur;
    }
};