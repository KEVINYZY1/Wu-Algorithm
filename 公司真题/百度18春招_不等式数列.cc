/*
不等式数列
时间限制：1秒
空间限制：32768K
度度熊最近对全排列特别感兴趣,对于1到n的一个排列,度度熊发现可以在中间根据大小关系插入合适的大于和小于符号(即 '>' 和 '<' )使其成为一个合法的不等式数列。但是现在度度熊手中只有k个小于符号即('<'')和n-k-1个大于符号(即'>'),度度熊想知道对于1至n任意的排列中有多少个排列可以使用这些符号使其为合法的不等式数列。 
输入描述:
输入包括一行,包含两个整数n和k(k < n ≤ 1000)


输出描述:
输出满足条件的排列数,答案对2017取模。

输入例子:
5 2

输出例子:
66
*/

/*
#include <iostream>
#include <vector>
using namespace std;

//全排列超时了= =
void dfs(int low, int high, int k, vector<int> &nums, int &count){
    if(low == high){
        //判断nums数组是否符合标准
        int temp = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1])
                temp++;
        }
        if(temp == k)
            count++;
        return;
    }
    for(int i = low; i <= high; i++){
        swap(nums[i], nums[low]);
        dfs(low+1, high, k, nums, count);
        swap(nums[i], nums[low]);
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    int count = 0;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        nums[i] = i + 1;
    }
    dfs(0, n-1, k, nums, count);
    cout << count << endl;
}


#include <iostream>
#include <vector>
using namespace std;

//剪枝的关键就是一直维护一个变量small
void dfs(vector<bool> &used, int n, int k, vector<int> nums, int small, int &count){
    const int len = nums.size();
    if(len == n){
        if(small == k)
            count++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(used[i])
            continue;
        used[i] = true;
        nums.push_back(i + 1);
        if(len > 0 && nums[len] > nums[len-1]){
            small++;
        }
        if(small > k)
            return;
        dfs(used, n, k, nums, small, count);
        used[i] = false;
        nums.pop_back();
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    int count = 0;
    vector<bool> used(n, false);
    dfs(used, n, k, vector<int>(), 0, count);
    cout << count << endl;
}

*/

/*dp
dp[i][j] = (dp[i - 1][j - 1] * (i - j) + dp[i - 1][j] * (j + 1)) % 2017;
dp[i][j]表示有i个数字及j个小于号所能组成的数量(大于号数量当然是i - j - 1次，后面需要使用)
而加入第i + 1个数字时，分以下四种情况：
1.如果将i+1插入当前序列的开头，即有了1<2，加入后成为3>1<2，会发现等于同时加入了一个大于号！(此时可以无视1与2之间的关系，因为i+1>i)
2.如果将i+1插入当前序列末尾,即1<2变成了 1<2<3，会发现等于同时加入了一个小于号！ (此时可以无视1与2之间的关系，因为i+1>i)
3.如果将i+1加入一个小于号之间，即已经有 1<2了，向中间加入3,会发现变成了1<3>2，等于同时加入了一个大于号！
4.如果将i+1加入一个大于号中间，即有了2>1，变成了2<3>1，等于同时加入了一个小于号！
综上所述，dp[i][j]等于以上四种情况之和：
dp[i - 1][j]                                     //将i加在开头等于加入一个大于号，即要求i-1个数时已经有了j个小于号
dp[i - 1][j - 1]                               //将i加在末尾等于加入一个小于号，即要求i-1个数时已经有了j-1个小于号
dp[i - 1][j] * j                                //将i加在任意一个小于号之间，等于加入了一个大于号；即要求i-1个数时已经有了j个小于号，每个小于                                                         号都可以进行这样的一次插入
dp[i - 1][j - 1] * (i- j - 1)              //将i加载任意一个大于号之间，等于加入了一个小于号；即要求i-1个数时有了j-1个小于号，而此时共有
                                                        (i - 1) - (j - 1)- 1个大于号，每个大于号都要进行一次这样的操作
合并同类项即为
 dp[i][j] = (dp[i - 1][j - 1] * (i - j) + dp[i - 1][j] * (j + 1)) 
最后要记得取模
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <limits.h>
 
using namespace std;
 
int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int> > dp(n + 1, vector<int>(n+1, 0));
    dp[2][0] = 1;
    dp[2][1] = 1;
    for (int i = 3; i <= n; ++i){
        dp[i][0] = 1;
        dp[i][i - 1] = 1;
    }
    for (int i = 3; i <= n; ++i){
        for (int j = 1; j <= i - 2; ++j){
            dp[i][j] = (dp[i - 1][j - 1] *(i - j))%2017 + (dp[i - 1][j] *(j + 1))%2017;
        }
    }
    cout << dp[n][k]%2017 << endl;
    return 0;
}