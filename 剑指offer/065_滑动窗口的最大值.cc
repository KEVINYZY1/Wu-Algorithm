#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
		vector<int> result;
        if(num.empty()||size==0)
            return result;
        int maxIndex=0;
        const int len=num.size();
        if(size>len)
            return result;
        for(int i=1;i<size;i++){
            if(num[i]>num[maxIndex])
                maxIndex=i;
        }
        result.push_back(num[maxIndex]);
        int startIndex=1;
        int endIndex=size;
        while(endIndex<len){
            if(num[endIndex]>=num[maxIndex]){
                maxIndex=endIndex;
            }
            
            else if(maxIndex<startIndex || maxIndex>endIndex){
                maxIndex=findMaxIndex(num,startIndex,endIndex);
            }
            result.push_back(num[maxIndex]);
            startIndex++;
            endIndex++;
        }
        return result;
    }
    int findMaxIndex(const vector<int>& num,int startIndex,int endIndex){
        int maxIndex=startIndex;
        for(int i=startIndex;i<=endIndex;i++){
            if(num[i]>=num[maxIndex])
                maxIndex=i;
        }
        return maxIndex;
    }
};