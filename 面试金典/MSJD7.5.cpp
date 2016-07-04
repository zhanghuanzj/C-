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

class Bipartition {
public:
    pair<double,double> getMid(vector<Point> A)
    {
        double ax = 0,ay = 0;
        for(auto p:A)
        {
            ax += p.x;
            ay += p.y;
        }
        ax /= 4;
        ay /= 4;
        return make_pair(ax,ay);
    }
    vector<double> getBipartition(vector<Point> A, vector<Point> B) {
        pair<double,double> pa = getMid(A);
        pair<double,double> pb = getMid(B);
        double k = (pb.second-pa.second)/(pb.first-pa.first);
        double z = pb.second-k*pb.first;
        vector<double> result;
        result.push_back(k);
        result.push_back(z);
        return result;
    }
};