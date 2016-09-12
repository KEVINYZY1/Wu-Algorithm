#include<vector>
#include<algorithm>
using namespace std;
//方法一，三次翻转即可。注：需要考虑k大于数组长度的情况
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        k=k %nums.size();
        k=nums.size()-k;
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};

//方法二，效率最佳，利用了数论
//使用了循环赋值，而不是两两交换，这样将赋值的次数变为原来的三分之一
//若有两个正整数m、n，且gcd(m,n)=d，那么序列{m%n, 2m%n, 3m%n,..., nm%n}一定是{0, d, 2d,..., n-d}的某个排列并重复出现d次，其中%号代表求模操作。
//比如若m=6, n=8，d=gcd(m,n)=2，那么{6%8, 12%8, 18%8,..., 48%8}即为{0，2，4，6}的某个排列并重复。
//特别地，若m、n互素，d=1，那么序列{m%n,2m%n,3m%n,...,(n-1)m%n}实际上就是{1, 2, 3,..., n-1}的某个排列。
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        //把问题转化为向左位移k'
        k=nums.size()-(k%nums.size());
        //取全长和前段（移动的位数）的最大公因数
        // 链数为gcd(m,n)。链中元素个数为n/gcd(m,n)。
        if(k==nums.size())
            return;
        int r= gcd(nums.size(),k);
        while(r--)
            rotateCycle(nums,nums.begin()+r,k);
    }
private:
//辗转相除法求x和y的最大公约数，假设x大于等于y
    int gcd(int x,int y){
        if(x<y)return gcd(y,x);
        int r=x%y;
        while(r){
            x=y;
            y=r;
            r=x%y;
        }
        return y;
    }
    void rotateCycle(vector<int>& nums,vector<int>::iterator init, int k){
        int storeInit=*init;
        auto ptr1=init;
        auto ptr2=init+k;
        while(ptr2!=init){
            *ptr1=*ptr2;
            ptr1=ptr2;
            if (nums.end() - ptr2 > k)   //还没有到达最后一个元素  
                ptr2 += k;  
            else
                ptr2 = nums.begin() + (k - (nums.end() - ptr2));
        }
        *ptr1 = storeInit; 
    }
};