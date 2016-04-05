#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

struct Point
{
	Point(double a,double b):x(a),y(b){}
	Point():x(0),y(0){}
	double x;
	double y;
};
Point p;
double dist(Point p1,Point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double cos(Point q)
{
	return ((q.x-p.x)*(-p.x)+(q.y-p.y)*(-p.y))/(sqrt(pow(p.x,2)+pow(p.y,2))*sqrt(pow(q.x-p.x,2)+pow(q.y-p.y,2)));
}
bool compare(const Point &p1,const Point &p2)
{
	if (cos(p1)!=cos(p2))
	{
		return cos(p1)>cos(p2);
	}
	else
	{
		return p1.x<p2.x;
	}
}
Point getStackSecond(stack<Point> &ps)
{
	Point p = ps.top();
	ps.pop();
	Point second = ps.top();
	ps.push(p);
	return second;
}
bool isLeft(const Point &p1,const Point &p2)
{
	return (p1.x*p2.y-p1.y*p2.x)>0;
}
bool isNeedAdd(stack<Point> &ps,Point &pi)
{
	Point p1 = ps.top();
	Point p2 = getStackSecond(ps);
	return isLeft(Point(p1.x-p2.x,p1.y-p2.y),Point(pi.x-p1.x,pi.y-p1.y));
}
double longestDistance(stack<Point> &ps)
{
	vector<Point> vec;
	while(ps.size()>0)
	{
		vec.push_back(ps.top());
		ps.pop();
	}
	double distance = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = i+1; j < vec.size(); ++j)
		{
			if (dist(vec[i],vec[j])>distance)
			{
				distance = dist(vec[i],vec[j]);
			}
		}
	}
	return distance;
}
double findFarthest2(vector<Point> points)
{
	if (points.size()<=1)
	{
		return 0;
	}
	else if (points.size()==2)
	{
		return dist(points[0],points[1]);
	}
	else 
	{
		//Find the leftest point
		int index = 0;
		for (int i = 1; i < points.size(); ++i)
		{
			if (points[index].x<points[index].x)
			{
				index = i;
			}
		}
		Point p0 = points[index];
		p = p0;
		vector<Point>::iterator it = points.begin()+index;
		points.erase(it);
		//sort the remain points
		sort(points.begin(), points.end(),compare);
		//create the stack init with p0 p1 p2
		stack<Point> pointStack;
		pointStack.push(p0);
		pointStack.push(points[0]);
		pointStack.push(points[1]);
		
		//iterate the remain points
		for (int i = 2; i < points.size(); ++i)
		{
			while(!isNeedAdd(pointStack,points[i]))
			{
				pointStack.pop();
			}
			pointStack.push(points[i]);
		}
		//caluculate the longest distance
		return longestDistance(pointStack);
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
		Point p(x,y);
		points.push_back(p);
	}
	cout<<findFarthest2(points)<<endl;
}