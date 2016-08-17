/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Comp{
  public:
    bool operator()(const Interval& a,const Interval& b)const{
        if(a.start < b.start) return true;
        else if(a.start==b.start) return a.end<b.end;
        return false;
    }
};
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if(intervals.empty()) return result;
        sort(intervals.begin(),intervals.end(),Comp());
        Interval temp = intervals.front();
        for(int i=1;i<intervals.size();++i){
            if(intervals[i].start<=temp.end){
				temp.end = max(temp.end,intervals[i].end);
			}else{
				result.push_back(temp);
				temp = intervals[i];
			}
        }
		result.push_back(temp);
		return result;
    }
};