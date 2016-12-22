#include<vector>
using namespace std;


//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
//不能使用除法。

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int>B;
        if(A.empty())
            return B;
        const int len=A.size();
        int temp=1;
        B.push_back(temp);
        for(int i=1;i<len;i++){
            temp*=A[i-1];
            B.push_back(temp);
        }
        temp=1;
        for(int i=len-2;i>=0;i--){
            temp*=A[i+1];
            B[i]*=temp;
        }
        return B;
    }
};