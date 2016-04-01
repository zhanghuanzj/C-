#include<iostream>
#include <vector>
using namespace std;


int main()
{
	int n;
	while (cin>>n)
	{
		int x;
		vector<int> vec;
		for (int i=0;i<n;++i)
		{
			cin>>x;
			vec.push_back(x);
		}
		int d1=-1,d2=10000;
		for (int i=1;i<n;++i)
		{
			if (vec[i]-vec[i-1]>d1)
			{
				d1 = vec[i]-vec[i-1];
			}
			if (i+1<n&&vec[i+1]-vec[i-1]<d2)
			{
				d2 = vec[i+1]-vec[i-1];
			}
		}
		int result = d2<=d1?d1:d2;
		cout<<result<<endl;
	}
}