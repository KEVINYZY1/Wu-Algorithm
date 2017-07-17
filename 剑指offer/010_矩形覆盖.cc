//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
//请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

class Solution {
public:
    int jumpFloorII(int number) {
		if (number <= 0)
            return -1;
        else if (number == 1)
            return 1;
        else
            return 2 * jumpFloorII(number - 1);
    }
};