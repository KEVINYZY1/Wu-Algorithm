#include<vector>
using namespace std;

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	const int len= numbers.size();
        int count=0;
        int index=0;
        for(int i=1;i<len;i++){
            if(numbers[i]==numbers[i-1]){
                count++;
                index=i;
            }
            else if(count==0)
                index=i+1;
        }
        if(index==len)
            return 0;
        else return numbers[index];
    }
};