#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//intervals已经是排序过了
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int insertIndex=-1;
        //insert
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i].start>=newInterval.start){
                insertIndex=i;
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
            if(i==intervals.size()-1){
                insertIndex==intervals.size();
                intervals.push_back(newInterval);
            }
        }
        //merge
        if(insertIndex==-1){//intervals为空
            intervals.push_back(newInterval);
            return intervals;
        }
        if(insertIndex>0 && intervals[insertIndex-1].end>=intervals[insertIndex].start){//与前一个节点merge
            intervals[insertIndex-1].end=max(intervals[insertIndex-1].end, intervals[insertIndex].end);
            intervals.erase(intervals.begin()+insertIndex);
            insertIndex--;
        }
        int rangeIndex=insertIndex+1;
        while(rangeIndex<intervals.size()){//与后面不确定多少个merge
            if(intervals[insertIndex].end<intervals[rangeIndex].start)
                break;
            rangeIndex++;
        }
        if(rangeIndex==insertIndex+1)
            return intervals;
        intervals[insertIndex].end=max(intervals[insertIndex].end, intervals[rangeIndex-1].end);
        intervals.erase(intervals.begin()+insertIndex+1, intervals.begin()+rangeIndex);
        return intervals;
    }
};