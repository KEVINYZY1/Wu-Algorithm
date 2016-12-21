#include<vector>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()<=4)
            return false;
        sort(numbers.begin(),numbers.end());
        int count0=0;
        for(int i=0;i<5;i++){
            if(numbers[i]==0)
                count0++;
        }
        int count=0;
        for(int i=0;i<4;i++){
            if(numbers[i]!=0 && numbers[i]+1<numbers[i+1])
                count+=numbers[i+1]-numbers[i]-1;
            if(numbers[i]!=0 && numbers[i]==numbers[i+1])
                return false;
        }
        if(count<=count0)
            return true;
        else return false;
    }
};