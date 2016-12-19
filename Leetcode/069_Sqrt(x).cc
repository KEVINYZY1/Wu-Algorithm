

//方法1，二分法
//也可以用来判断是不是一个完全平方数
//输入的x需要大于等于0，假设输入的x不为平方数时，输出它的平方根的向下取整
//大数问题要注意
class Solution1 {
public:
    int mySqrt(int x) {
        int high=x;
        int low=1;
        int mid=0;
        while(low<=high){
            mid=low+(high-low)/2;//防越界
            //unsigned long long tempX=mid*mid;可以换种方式来防止溢出
            if(mid==x/mid)
                return mid;
            else if(mid>x/mid)
                high=mid-1;
            else if(mid<x/mid)
                low=mid+1;
        }
        return high;//此时的high必然小于low，小于等于mid
    }
};

//方法2，牛顿迭代法求近似求平方根
/*
计算x2 = n的解，令f(x)=x2-n，相当于求解f(x)=0的解，如左图所示。
首先取x0，如果x0不是解，做一个经过(x0,f(x0))这个点的切线，与x轴的交点为x1。
同样的道理，如果x1不是解，做一个经过(x1,f(x1))这个点的切线，与x轴的交点为x2。
以此类推。
以这样的方式得到的xi会无限趋近于f(x)=0的解。
判断xi是否是f(x)=0的解有两种方法：
一是直接计算f(xi)的值判断是否为0，二是判断前后两个解xi和xi-1是否无限接近。
*/
class Solution2 {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        double res = 1, pre = 0;
        //while (res != pre) {//这里有点疑问，得执行多少次，才能一样，double类型的精度很高啊
        while (abs(res-pre)>0.1) {
            pre = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};