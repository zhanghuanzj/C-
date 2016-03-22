#include<iostream>  
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;  

int main()
{
	long long n,l;
	while (cin>>n>>l)
	{
		int position;
		vector<long long> positions;
		while (n--)
		{
			cin>>position;
			positions.push_back(position);
		}
		sort(positions.begin(),positions.end());
		auto it = unique(positions.begin(),positions.end());
		positions.erase(it,positions.end());
		double d = -1;
		for (size_t i=0;i<positions.size()-1;++i)
		{
			if (positions[i+1]-positions[i]>d)
			{
				d = positions[i+1]-positions[i];
			}
		}
		double edgeDistance = max(positions[0]-0,l-positions.back());
		cout<<setprecision(2)<<std::fixed<<max(d/2,edgeDistance)<<endl;
	}
	return 0;
}