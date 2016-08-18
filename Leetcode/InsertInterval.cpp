class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        int index = 0;
        bool isInsert = false;
        for(index=0;index<intervals.size();++index){
            if(isInsert){
                if(result.back().end<intervals[index].start){
                    result.push_back(intervals[index]);
				}else{
                    result.back().end = max(result.back().end,intervals[index].end);
                }
            }else{
                if(intervals[index].end<newInterval.start){
                    result.push_back(intervals[index]);
                }else if(intervals[index].start>newInterval.end){
                    result.push_back(newInterval);
                    result.push_back(intervals[index]);
                    isInsert = true;
                }else{
                    Interval temp = intervals[index];
                    temp.start = min(temp.start,newInterval.start);
                    temp.end = max(temp.end,newInterval.end);
                    result.push_back(temp);
                    isInsert = true;
                }
            }
        }
        if(!isInsert) result.push_back(newInterval);
        return result;
    }
};