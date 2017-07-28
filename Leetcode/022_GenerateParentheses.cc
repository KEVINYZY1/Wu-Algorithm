#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        findParenthesisCombinations(result, "", 0, 0, n);
        return result;
    }
private:
    void findParenthesisCombinations(vector<string>& result, string temp, int leftNum, int rightNum, int n){
        if (leftNum == n && rightNum == n) {
            result.push_back(temp);
            return;
        }
        //leftNum必然大于等于rightNum
        if (leftNum == rightNum) {
            findParenthesisCombinations(result, temp + '(', leftNum + 1, rightNum, n);
            return;
        }
        if (leftNum < n)
            findParenthesisCombinations(result, temp + '(', leftNum + 1, rightNum, n);
        if (rightNum < n)
            findParenthesisCombinations(result, temp + ')', leftNum, rightNum + 1, n);
    }
};