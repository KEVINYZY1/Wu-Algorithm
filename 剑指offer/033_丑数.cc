#include<vector>
using namespace std;

//把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 
//习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index == 0)
            return 0;
    	if (index == 1)
            return 1;
        int index2 = 0, index3 = 0, index5 = 0;
        int result = 1;
        vector<int> ugly;
        ugly.push_back(1);
        while (index > 1) {
            int minNum = min(ugly[index2] * 2, min(ugly[index3] * 3, ugly[index5] * 5));
            if (minNum == ugly[index2] * 2)
                index2++;
            else if (minNum == ugly[index3] * 3)
                index3++;
            else index5++;
            ugly.push_back(minNum);
            
            result = minNum;
            if (ugly[index3] * 3 <= result)//关键，有可能2*3和3*2都是一个数但是，index2++了，index3没有++
                index3++;
            if (ugly[index5] * 5 <= result)
                index5++;
            index--;
        }
        return result;
    }
};