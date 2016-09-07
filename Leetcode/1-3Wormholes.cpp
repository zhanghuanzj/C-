/*
ID: zhanghu14
PROG: wormhole
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;

//#define STDIO
#ifdef STDIO
#define  IN		cin
#define  OUT	cout
#else
#define  IN		fin
#define  OUT	fout
#endif

struct WornHole
{
	int x;
	int y;
};
bool check(const vector<int> &next,const vector<int> &pair)
{
	int n = next.size();
	for (int start=0;start<n;++start) 
	{
		int pos = start,count = 0;
		while(count<n)
		{
			pos = next[pos];
			if (pos==-1) break;
			pos = pair[pos];
			++count;
		}
		if (count==n) return true;
	}
	return false;
}
int solve(const vector<int> &next,vector<int> &pair)
{
	int index = 0,result = 0;
	for (;index<pair.size();++index) 
	{
		if (pair[index]==-1) break;
	}
	if (index==pair.size())
	{
		return check(next,pair)?1:0;
	}
	else
	{
		for (int i=index+1;i<pair.size();++i) 
		{
			if (pair[i]==-1)	//递归+回溯
			{
				pair[index] = i;
				pair[i] = index;
				result += solve(next,pair);
				pair[i] = pair[index] = -1;
			}
		}
	}
	return result;
}
int main()
{
	const string path = "wormhole";
	ifstream fin(path+".in");
	ofstream fout(path+".out");
	int n;
	while (IN>>n)
	{
		vector<WornHole> holes(n);
		for(int i=0;i<n;++i)
			IN>>holes[i].x>>holes[i].y;
		//右接邻处理
		vector<int> next_hole(n,-1);
		for (int i=0;i<n;++i) 
		{
			for (int j=0;j<n;++j) 
			{
				if (holes[j].x>holes[i].x && holes[j].y==holes[i].y)
				{
					if (next_hole[i]==-1 || holes[j].x<holes[next_hole[i]].x)
					{
						next_hole[i] = j;
					}
				}
			}
		}
		//配对
		vector<int> pair(n,-1);
		OUT<<solve(next_hole,pair)<<endl;
	}
}


