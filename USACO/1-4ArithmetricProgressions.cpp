/*
ID: zhanghu14
PROG: ariprog
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

int cost(vector<int> &hills,int height)
{
	int result = 0;
	for (auto h : hills) 
	{
		if (height-h>17)
		{
			result += pow(height-17-h,2);
		}
		else if(h>height)
		{
			result += pow(h-height,2);
		}
	}
	return result;
}

int main()
{
	const string path = "ariprog";
	ifstream fin(path+".in");
	ofstream fout(path+".out");

	
	int n,m;
	while (IN>>n>>m)
	{
		
		int size = 2*m*m;
		int maxGap = size/(n-1);
		vector<bool> hash(size+1,false);
		for (int i=0;i<=m;++i) 
		{
			for(int j=0;j<=m;++j)
			{
				hash[i*i+j*j] = true;
			}
		}
		bool isHas = false;
		for (int i=1;i<=maxGap;++i) //间隔
		{
			for (int j=0;j<=size-(n-1)*i;++j)  //起始
			{
				bool isOK = true;
				for (int k=0;k<n;++k) 
				{
					if (!hash[j+k*i])
					{
						isOK = false;
						break;
					}
				}
				if (isOK)
				{
					OUT<<j<<" "<<i<<endl;
					isHas = true;
				}
			}
		}
		if (!isHas)
		{
			OUT<<"NONE"<<endl;
		}
	}
}


