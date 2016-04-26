#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <set>
using namespace std;

int main()
{
	int n,t,m;
	while (cin>>n>>t>>m)
	{
		vector<int> a;
		int w;
		for (int i=0;i<n;++i)
		{
			cin>>w;
			a.push_back(w);
		}

		int result = 0;
		for (int i=1;i<(1<<n);++i)
		{
			int count = 0;
			int current = t;
			int tempm = m-1;
			for (int j=0;j<n;++j)
			{
				if ((1<<j)&i)
				{
					if (current>=a[j])
					{
						current -= a[j];
						count++;
					}
					else if(t>=a[j]&&tempm)
					{
						current = t-a[j];
						count++;
						tempm--;
					}
					//装不下
				}
			}
			result = max(result,count);
		}
		cout<<result<<endl;
	}

}