#include<vector>
#include<cassert>
using namespace std;

//1到n的数组，可能组成的二叉搜索树有多少种
//求多少种，dp更合适

//当数组为 1，2，3，4，.. i，.. n时，基于以下原则的BST建树具有唯一性：
//以i为根节点的树，其左子树由[0, i-1]构成， 其右子树由[i+1, n]构成。


/*卡兰特数定义

定义Count[i] 为以[0,i]能产生的Unique Binary Tree的数目，

如果数组为空，毫无疑问，只有一种BST，即空树，Count[0] =1

如果数组仅有一个元素{1}，只有一种BST，单个节点 Count[1] = 1

如果数组有两个元素{1,2}， 那么有如下两种可能
1                       2
  \                    /
    2                1
Count[2] = Count[0] * Count[1]   (1为根的情况)+ Count[1] * Count[0]  (2为根的情况)

再看一遍三个元素的数组，可以发现BST的取值方式如下：
Count[3] = Count[0]*Count[2]  (1为根的情况)
               + Count[1]*Count[1]  (2为根的情况)
               + Count[2]*Count[0]  (3为根的情况)

所以，由此观察，可以得出Count的递推公式为
Count[i] = ∑ Count[0...k] * [ k+1....i]     0<=k<i-1
*/
class Solution {
public:
    int numTrees(int n) {
        assert(n>0);
        vector<int>count(n+1,0);
        count[0]=count[1]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i+1;j++){
                count[i+1]+=count[j]*count[i-j];
            }
        }
        return count[n];
    }
};