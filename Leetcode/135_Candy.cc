#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        const int len=ratings.size();
        if(len==1)
            return 1;
        vector<int> candys(len,0);
        candys[0]=1;
        //从左到右扫描一遍，使得右边比左边得分高的小朋友糖果数比左边多。
        for(int i=1;i<len;i++){
            if(ratings[i]>ratings[i-1])
                candys[i]=candys[i-1]+1;
            else candys[i]=1;
        }
        //再从右到左扫描一遍，使得左边比右边得分高的小朋友糖果数比右边多
        for(int i=len-1;i>0;i--){
            if(ratings[i]<ratings[i-1] && candys[i]>=candys[i-1])//还有个判断
                candys[i-1]=candys[i]+1;
        }
        int sum=0;
        for(int i=0;i<len;i++){
            sum+=candys[i];
        }
        return sum;
    }
};