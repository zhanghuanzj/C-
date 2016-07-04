/*
struct Point {
    int x;
    int y;
    Point() :
            x(0), y(0) {
    }
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};*/
class DenseLine {
public:
    pair<double,double> getKey(Point a,Point b)
    {
        double k = (b.y-a.y)/(b.x-a.x);
        double z = b.y-k*b.x;
        return make_pair(k,z);
    }
    vector<double> getLine(vector<Point> p, int n) {
        map<pair<double,double>,int> count;
        int record = 0;
        pair<double,double> key;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                pair<double,double> x = getKey(p[i],p[j]);
                if (count.count(x))
                {
                    count[x] ++;
                }
                else
                {
                    count[x] = 1;
                }
                if (count[x]>record)
                {
                    record = count[x];
                    key = x;
                }
            }
        }
        
        vector<double> result;
        result.push_back(key.first);
        result.push_back(key.second);
        return result;
    }
};