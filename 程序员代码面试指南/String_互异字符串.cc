#include <string>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isDeformation(string& l, string& r) {
        if (l.size() != r.size()) //排除了对下面公用一个哈希表不利的边界条件
            return false;
        vector<int> hash(256);
        for (auto item : l) {
            hash[item]++;
        }  
        for (auto item : r) {
            if(--hash[item] < 0)
                return false;
        }
        return true;
    }
};

int main () {
    Solution s;
    string temp1 = "abcd";
    string temp2 = "dcba";
    assert(s.isDeformation(temp1, temp2) == true);
    cout << "good" << endl;
}