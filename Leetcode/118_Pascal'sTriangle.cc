#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows<=0)
            return result;
        result.push_back(vector<int>(1,1));
        numRows--;
        while(numRows>0){
            vector<int>temp;
            temp.push_back(1);
            const int len=result[result.size()-1].size();
            const int index=result.size()-1;
            if(len>1){
                for(int i=0;i<len-1;i++){
                    temp.push_back(result[index][i]+result[index][i+1]);
                }
            }
            temp.push_back(1);
            result.push_back(temp);
            numRows--;
        }
        return result;
    }
};