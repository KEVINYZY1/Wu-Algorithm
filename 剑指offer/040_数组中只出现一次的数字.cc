#include<vector>
using namespace std;

/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		if (data.empty())
            return;
        //先异或遍历数组
        const int len = data.size();
        int num = data[0];
        for (int i = 1; i < len; i++) {
            num ^= data[i];
        }
        //确定num从右边开始，第一个有1的比特位
        int base = 1;
        int temp = num & base;
        while (temp== 0) {
            base = base << 1;
            temp = num & base;
        }
        //按该比特位base，分别异或
        bool first = false;
        bool second = false;
        for (int i = 0; i < len; i++) {
            if (data[i] & base) {
                if (!first) {
                    *num1 = data[i];
                    first = true;
                } else {
                    *num1 ^= data[i];
                }
            } else {
                if (!second) {
                    *num2 = data[i];
                    second = true;
                } else {
                    *num2 ^= data[i];
                }
            }
        }
    }
};