#include<string>
#include<vector>
using namespace std;
//方法一，利用算法导论第四章第一节所说的，将问题转换为求一个数组中的最小子数组问题
//然而会超时，= =。时间复杂度应该是O(nlgn)
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
    //将prices数组转化为代表每日价格变化的数组
    //为了能保证in-place，需要从后面向前面转换
        if (prices.empty())
            return 0;
        for(int i=prices.size()-1;i>0;i--){
            prices[i]=prices[i-1]-prices[i];
            prices[i]*=-1;
        }
        prices[0]=0;
        return findMaxSumSubarray(prices,0,prices.size()-1);
    }
private:
    //返回跨越中点的最大子数组之和
    int findMaxSumCrossSubarray(vector<int> prices, int low,int high){
        int mid=(low+high)/2;
        int rightMaxSum=0;
        int tempSum=0;
        for(int i=mid+1;i<=high;i++){
            tempSum+=prices[i];
            rightMaxSum=max(rightMaxSum,tempSum);
        }
        int leftMaxSum=0;
        tempSum=0;
        for(int i=mid-1;i>=low;i--){
            tempSum+=prices[i];
            leftMaxSum=max(leftMaxSum,tempSum);
        }
        return (leftMaxSum+rightMaxSum+prices[mid]);
    }
    //返回prices数组中的最大子数组之和
    int findMaxSumSubarray(vector<int> prices, int low,int high){
        if(low==high)
            return prices[low];
        int mid=(low+high)/2;
        int leftSum=findMaxSumSubarray(prices,low,mid);
        //这里的low和high使用的时闭区间，如果用的是左开右闭，则会栈溢出
        //以后这类问题一律使用闭区间把
        int rightSum=findMaxSumSubarray(prices,mid+1,high);
        int midSum=findMaxSumCrossSubarray(prices,low,high);
        if(leftSum>=rightSum&&leftSum>=midSum)
            return leftSum;
        else if(rightSum>=leftSum&&rightSum>=midSum)
            return rightSum;
        else return midSum;
    }
};
//方法二，动态规划