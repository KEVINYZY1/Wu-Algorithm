#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

//假设最小窗口唯一
/*
用一个哈希表记录目标字符串每个字母的个数，一个哈希表记录窗口中每个字母的个数。
先找到第一个有效的窗口，用两个指针标出它的上界和下界。
然后每次窗口右界向右移时，将左边尽可能的右缩，右缩的条件是窗口中字母的个数不小于目标字符串中字母的个数。
*/
class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        const int lens=s.size();
        const int lent=t.size();
        if(!lens || lens<lent)
            return result;
        int count=0;//如果满足和lent一样大，则是符合的窗口。
        int minLengthWin=INT_MAX;
        int leftIndex=0;
        
        //构造一个哈希表
        unordered_map<char,int> table;
        for(int i=0; i<lent; i++){
            if(table.find(t[i])==table.end())
                table[t[i]]=1;
            else table[t[i]]++;
        }
        //由于窗口的点不规律，和30题不一样，需要我们用数组记录
        vector<int> index;
        
        bool isRightMove=false;
        //应该是窗口直接先找到包含t的字符串，再考虑缩小范围
        unordered_map<char,int> window;
        for(int i=0; i<lens; i++){
            if(table.find(s[i])!=table.end()){
                index.push_back(i);
                
                if(window.find(s[i])==window.end())
                    window[s[i]]=1;
                else window[s[i]]++;
                if(window[s[i]]<=table[s[i]])//关键！
                    count++;

                //边界情况，比如"bba" "ab"这种，需要考虑找到有效窗口之后，也需要对有效窗口进行右移
                if(count==lent && !isRightMove){
                    isRightMove=true;
                    if(minLengthWin>(i-index[leftIndex]+1)){
                        result=s.substr(index[leftIndex],i-index[leftIndex]+1);
                        minLengthWin=i-index[leftIndex]+1;
                    }
                }
                
                if(isRightMove){//窗口右移
                    while(1){
                        if(window[s[index[leftIndex]]]>table[s[index[leftIndex]]]){
                            window[s[index[leftIndex]]]--;
                            leftIndex++;
                        }
                        else break;
                    }
                }
                
                if(count==lent){
                    isRightMove=true;
                    if(minLengthWin>(i-index[leftIndex]+1)){
                        result=s.substr(index[leftIndex],i-index[leftIndex]+1);
                        minLengthWin=i-index[leftIndex]+1;
                    }
                }
            }
        }
        
        return result;
    }
};