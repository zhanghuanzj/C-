#include<iostream>
#include <cmath>
using namespace std;


int main()
{
	long long r,x1,y1,x2,y2,d;
	while (cin>>r>>x1>>y1>>x2>>y2)
	{
		d = sqrt(pow(y2-y1,2)+pow(x2-x1,2))-r;
		int step = 0;
		while (d>=(2*r))
		{
			d -= 2*r;
			++step;
		}
		if (d)
		{
			++step;
		}
		cout<<step<<endl;
	}
}