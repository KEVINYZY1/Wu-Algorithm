/*
最大映射
有 n 个字符串，每个字符串都是由 A-J 的大写字符构成。现在你将每个字符映射为一个 0-9 的数字，不同字符映射为不同的数字。这样每个字符串就可以看做一个整数，唯一的要求是这些整数必须是正整数且它们的字符串不能有前导零。现在问你怎样映射字符才能使得这些字符串表示的整数之和最大？

输入描述:
每组测试用例仅包含一组数据，每组数据第一行为一个正整数 n ， 接下来有 n 行，每行一个长度不超过 12 且仅包含大写字母 A-J 的字符串。 n 不大于 50，且至少存在一个字符不是任何字符串的首字母。


输出描述:
输出一个数，表示最大和是多少。

输入例子:
2
ABC
BCA

输出例子:
1875
*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
 
bool cmp(pair<char, long>a, pair<char, long>b){
    return a.second > b.second;
}
 
int main(){
    int n;
    while(cin>>n){
        map<char, long long>m;
        set<char> f; //保存首字母
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            long long b = 1;
            for(string::reverse_iterator i=s.rbegin();i<s.rend();i++){
                m[*i] += b;
                b *= 10;
            }
            f.insert(s[0]);
        }
        vector<pair<char, long long> >v(m.begin(), m.end());//map可以这么赋值
        //之前写错，误以为map维护的longlong已经排好序了
        sort(v.begin(), v.end(), cmp);
        int i = v.size() - 1;
        // 所有字母出现时，找到没有出现在首字母中权重最小的字母
        //如果10个字母都出现过，就不能按照权重分配0-9，因为可能有的虽然权重最小，但是出现在开头过，不能为0
        while(v.size()==10 && i>=0 && f.find((v[i]).first)!=f.end()){
            i--;
        }
        unsigned long long res = 0;
        if(i!=(v.size()-1)){
            // 最小字母赋值0，删除即可
            v.erase(v.begin() + i);
        }
        int b = 9;
        for(int i=0;i<v.size();i++){
            res += b * v[i].second;
            b--;
        }
        cout<<res<<endl;
    }
    return 0;
}
