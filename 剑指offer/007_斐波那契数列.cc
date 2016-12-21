//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。

class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0)
            return 0;
		int num1=1;
        int num2=1;
        if(n==1 || n==2)
            return num1;
        while(n>2){
            int temp=num2;
            num2=num1+num2;
            num1=temp;
    		n--;
        }
        return num2;
    }
};