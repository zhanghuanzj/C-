#include<iostream>
#include <set>
using namespace std;


int main()
{
	int p,n;
	while (cin>>p>>n)
	{
		int x,result = -1;
		set<int> setp;
		for (int i=0;i<n;++i)
		{
			cin>>x;
			if (result==-1)
			{
				if (setp.count(x%p))
				{
					result = i+1;
				}
				else
				{
					setp.insert(x%p);
				}
			}
		}
		cout<<result<<endl;
	}
}