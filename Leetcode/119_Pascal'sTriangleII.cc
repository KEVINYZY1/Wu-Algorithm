#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if(rowIndex<0)
            return result;
        result.push_back(1);
        rowIndex--;
        while(rowIndex>=0){
            for(int i=result.size()-1;i>0;i--){
                result[i]=result[i]+result[i-1];
            }
            result.push_back(1);
            rowIndex--;
        }
        return result;
    }
};