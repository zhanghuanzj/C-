/*
ID: zhanghu14
PROG: milk2
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
	const string path = "milk2";
	ifstream fin(path+".in");
	ofstream fout(path+".out");

	int n;
	while (fin>>n)
	{
		vector<pair<int,int>> record;
		for (int i=0;i<n;++i)
		{
			pair<int,int> p;
			fin>>p.first>>p.second;
			record.push_back(p);
		}
		sort(record.begin(),record.end());
		pair<int,int> time = record.front();
		int milking = 0,idle = 0;
		for (int i=1;i<n;++i)
		{
			if (record[i].first <= time.second)
			{
				time.second = max(record[i].second,time.second);
			}
			else
			{
				idle = max(idle,record[i].first-time.second);
				milking = max(milking,time.second-time.first);
				time = record[i];
			}
		}
		milking = max(milking,time.second-time.first);
		fout<<milking<<" "<<idle<<endl;
	}
}


