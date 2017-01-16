#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        s.insert(n);
        while(n!=1){
            int temp=0;
            while(n){
                temp+=pow((n%10),2);
                n/=10;
            }
            n=temp;
            if(s.find(n)!=s.end())
                return false;
            s.insert(n);
        }
        return true;
    }
};