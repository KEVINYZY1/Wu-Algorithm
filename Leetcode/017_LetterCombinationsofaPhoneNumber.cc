#include<map>
#include<vector>
#include<string>
using namespace std;

//还是一个全排列的问题
//其实不需要用map，vector<string>也可以
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        digitLetter['2'] = "abc";
        digitLetter['3'] = "def";
        digitLetter['4'] = "ghi";
        digitLetter['5'] = "jkl";
        digitLetter['6'] = "mno";
        digitLetter['7'] = "pqrs";
        digitLetter['8'] = "tuv";
        digitLetter['9'] = "wxyz";
        if (digits.empty())
            return result;
        findLetterCombinations(0, digits, "", result);
        return result;
    }
private:
    map<char,string>digitLetter;
    void findLetterCombinations(int index, string digits, string temp, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = 0;i < digitLetter[digits[index]].size(); i++) {
            findLetterCombinations(index + 1, digits, temp + digitLetter[digits[index]][i], result);
        }
    }
};