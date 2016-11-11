class Solution {
public:
//此题类似于求斐波那契数列的和
//递归会超时
    int climbStairs(int n) {
        if(n==0||n==1)return 1;
        int onestep=1;
        int twostep=1;
        int all=0;
        for(int i=1;i<n;++i){
            int temp=onestep+twostep;
            onestep=twostep;
            twostep=temp;
            //all=temp;
        }
        return twostep;
    }
};