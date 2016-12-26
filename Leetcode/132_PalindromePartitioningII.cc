#include<string>
#include<vector>
using namespace std;

//Dfs可以来做，但是超时
//dp
//寻找最短cut数，D[i] = 区间[i,n]之间最小的cut数，n为字符串长度， 则D[i] = min(1+D[j+1] )    i<=j <n
//判断回文子字符串，定义函数P[i][j] = true if [i,j]为回文，那么P[i][j] = str[i] == str[j] && P[i+1][j-1];
class Solution {
public:
    int minCut(string s) {
        int result=0;
        if(s.empty())
            return result;
        const int n = s.length();
		vector<vector<bool> > isPal (n,vector<bool>(n,false));
		vector<int> cut(n,0);
		for (int j = 0; j < n; j++) {
			cut[j] = j;//最多切j次
			for (int i = 0; i <= j; i++) {
				//如果子串 s[i...j]是回文串
				if (s[i] == s[j] && (j-i <= 1 || isPal[i+1][j-1])) {
					isPal[i][j] = true;
					if (i > 0)
						cut[j] = min(cut[j], cut[i-1] + 1);
					else
						cut[j] = 0; //如果 s[0...j]是回文串，则说明不需要切割
				}
			}
		}
		return cut[n-1];
    }
};