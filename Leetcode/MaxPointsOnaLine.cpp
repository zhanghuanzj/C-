/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int result = 0;
        for(int i=0;i<points.size();++i){
            map<double,int> record;
            int count = 0;
            int dup = 0;
            int cur = 1;
            for(int j=0;j<points.size();++j){
                if(i==j) continue;
                int dy = points[j].y-points[i].y;
                int dx = points[j].x-points[i].x;
                if(dx==0 && dy==0){
                    ++dup;
                }else if(dx==0){
                    count = count==0?2:(count+1);
                    cur = max(cur,count);
                }else{
                    double k = ((double)dy)/dx;
                    record[k] = record[k]==0?2:(record[k]+1);
                    cur = max(cur,record[k]);
                }
            }
            result = max(result,cur+dup);
        }
        return result;
    }
};