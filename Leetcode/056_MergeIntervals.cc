#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty() || intervals.size()==1)//只有一个就直接返回
            return intervals;
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            return a.start<b.start;
        });
        int startIndex=1;
        //先给result插入一个
        if(intervals[1].start<=intervals[0].end){//等号不能忘
            Interval temp(intervals[0].start, max(intervals[1].end,intervals[0].end));//[[1,4],[2,3]]这种情况
            result.push_back(temp);
            startIndex=2;
        }
        else result.push_back(intervals[0]);
        //然后将intervals成员依次和result的末尾进行比较
        for(; startIndex<intervals.size(); startIndex++){
            if(intervals[startIndex].start <= (result.end()-1)->end){//要记得end()代表的是尾后指针啊
                Interval temp((result.end()-1)->start, max(intervals[startIndex].end, (result.end()-1)->end));//[[1,4],[2,3]]这种情况
                result.pop_back();
                result.push_back(temp);
            }
            else result.push_back(intervals[startIndex]);
        }
        return result;
    }
};