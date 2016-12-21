#include<vector>
using namespace std;

//输入n个整数，找出其中最小的K个数。
//例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        const int len=input.size();
        vector<int> result;
        if(k==0||k>len)
            return result;
        if(k==len)
            return input;
        findKNums(input,result,k,0,len-1);
        return result;
    }
private: 
    void findKNums(vector<int>&input,vector<int>&result,int k,int start,int end){
        if(start>end)
            return ;
        int pivotIndex=start;
        int pivot=input[pivotIndex];
        int leftIndex=start+1;
        for(int i=start+1;i<=end;i++){
            if(input[i]<pivot){
                swap(input[i],input[leftIndex]);
                leftIndex++;
            }
        }
        if(leftIndex!=start+1){
        	swap(input[pivotIndex],input[leftIndex-1]);
            leftIndex--;
        }
        else leftIndex=start;
        
        if(k==leftIndex-start+1){
            for(int i=start;i<=leftIndex;i++)
            	result.push_back(input[i]);
        }
        else {
            if(k<leftIndex-start+1){
            	findKNums(input,result,k,start,leftIndex-1);
            }
            else {
                for(int i=start;i<=leftIndex;i++)
            		result.push_back(input[i]);
                findKNums(input,result,k-(leftIndex-start+1),leftIndex+1,end);
            }
        }
    }
};