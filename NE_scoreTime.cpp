#include<iostream>  
#include <vector>
#include <algorithm>
using namespace std;  

bool compare(pair<long long,long long> p1,pair<long long,long long> p2)
{
	return p1.second<p2.second;
}
int main()
{
	long long n,r,avg;
	while(cin>>n>>r>>avg)
	{
		long long totalTime = 0,a,b,score=0,target = n*avg;
		vector<pair<long long,long long>> record;
		while (n--)
		{
			cin>>a>>b;
			record.push_back(make_pair(a,b));
			score += a;
		}
		sort(record.begin(),record.end(),compare);
		for (int i=0;i<record.size();++i)
		{
			while (score<target)
			{
				if (record[i].first<r)
				{
					record[i].first++;
					score++;
					totalTime += record[i].second;
				}
				else
				{
					break;
				}
			}
		}
		cout<<totalTime<<endl;
	}
	return 0;
}