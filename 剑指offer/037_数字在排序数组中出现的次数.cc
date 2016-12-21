#include<vector>
using namespace std;

class Solution {
public:
    //假设k肯定存在
    int GetNumberOfK(vector<int> data ,int k) {
        int startIndex=0;
        int endIndex=0;
        if(data.empty())
            return 0;
        const int len=data.size();
        int low=0,high=len-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(data[mid]==k){
                if(mid>0 && data[mid]!=data[mid-1]){
                    startIndex=mid;
                    break;
                }
                else if(mid==0){
                    startIndex=mid;
                    break;
                }
                high=mid-1;
            }
            else if(data[mid]<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        low=0;high=len-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(data[mid]==k){
                if(mid<len-1 && data[mid]!=data[mid+1]){
                    endIndex=mid;
                    break;
                }
                else if(mid==len-1){
                    endIndex=mid;
                    break;
                }
                low=mid+1;
            }
            else if(data[mid]<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(endIndex==startIndex){
            if(data[endIndex]!=k)
                return 0;
        }
        return endIndex-startIndex+1;
    }
};