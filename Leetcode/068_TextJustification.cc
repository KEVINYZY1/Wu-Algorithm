#include<string>
#include<vector>
using namespace std;

//效率很低，有待优化
//姑且假设words中字符串长度没有大于maxWidth
//这题主要难点在于边界条件过多
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        if(words.empty())
            return result;
        int countSize=0;
        int countWords=0;
        int beginIndex=0;
        int endIndex=0;
        for(int i=0; i<words.size(); i++){
            countSize+=words[i].size();
            countWords++;
            if((countSize+countWords-1) > maxWidth){
                endIndex=i;
                string temp;
                int sum=0;
                int storeBeginIndex=beginIndex;
                while(beginIndex<endIndex){
                    sum+=words[beginIndex].size();
                    beginIndex++;
                }
                countWords--;
                beginIndex=storeBeginIndex;
                if(countWords==1){//单独考虑一行一个单词的情况，要求把空格全放在单词后面
                    temp+=words[beginIndex];
                    while(temp.size()<maxWidth)
                        temp+=' ';
                    result.push_back(temp);
                    beginIndex++;
                    countSize=words[beginIndex].size();
                    countWords=1;
                    continue;
                }
                int spaces=(maxWidth-sum)/(countWords-1);
                int margin=(maxWidth-sum)%(countWords-1);//可能不均匀的空格
                string space;
                while(spaces--)
                    space+=' ';
                while(beginIndex<endIndex){
                    if(!temp.empty()){
                        temp+=space;
                    }
                    if(!temp.empty() && margin){
                        temp+=' ';
                        margin--;
                    }
                    temp+=words[beginIndex];
                    beginIndex++;
                }
                result.push_back(temp);
                countSize=words[beginIndex].size();
                countWords=1;//得多想想
            }
        }
        string last;
        while(last.size() < maxWidth){
            while(endIndex<words.size()){
                if(!last.empty())
                    last+=' ';
                last+=words[endIndex];
                endIndex++;
            }
            if(last.size() == maxWidth)
                break;
            last+=' ';
        }
        result.push_back(last);
        return result;
    }
};