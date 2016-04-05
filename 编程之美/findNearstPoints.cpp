#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct Point
{
	Point(double a,double b):x(a),y(b){}
	double x;
	double y;
};
bool com(Point p1,Point p2)
{
	return p1.y<p2.y;
}
double dist(Point p1,Point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double findNearstPoint(vector<Point> points,double left,double right)
{
	int count = 0;
	vector<int> index;
	for (size_t i=0;i<points.size();++i)
	{
		if (points[i].x>=left&&points[i].x<=right)
		{
			count++;
			index.push_back(i);
		}
	}
	if (count<=1)
	{
		return 0x7fffffff;
	}
	else if (count==2)
	{
		return dist(points[index[0]],points[index[1]]);
	}
	else{
		double mid = (left+right)/2;
		double lMin = findNearstPoint(points,left,mid);
		double rMin = findNearstPoint(points,mid,right);
		double min_dis = lMin<rMin?lMin:rMin;
		vector<Point> temp;
		for(auto p : points)
		{
			if ((p.x>=mid-min_dis)&&(p.x<=mid+min_dis))
			{
				temp.push_back(p);
			}
		}
		sort(temp.begin(),temp.end(),com);
		for (size_t i = 0; i < temp.size(); ++i)
		{
			if (temp[i].x<=mid)
			{
				for (size_t j = 0; j < temp.size(); ++j)
				{
					if (temp[j].x>mid&&temp[j].y<temp[i].y+min_dis)
					{
						min_dis = min_dis<dist(temp[i],temp[j])?min_dis:dist(temp[i],temp[j]);
					}
				}
			}
		}
		return min_dis;
	}
}

int main()
{
	double x,y;
	double r=-10000,l=10000;
	vector<Point> points;
	int n;
	cin>>n;
	while (n--)
	{
		cin>>x>>y;
		if (x<l)
		{
			l = x;
		}
		if (x>r)
		{
			r = x;
		}
		Point p(x,y);
		points.push_back(p);
	}
	cout<<findNearstPoint(points,l,r)<<endl;
}