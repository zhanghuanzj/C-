/*
ID: zhanghu14
PROG: combo
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

bool check(int x,int y,int n)
{
	for (int i=0;i<5;++i) 
	{
		int value = (x+i-2+n)%n;
		if (value==y)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	const string path = "combo";
	ifstream fin(path+".in");
	ofstream fout(path+".out");
	int n;
	while (IN>>n)
	{
		int arr[2][3] = {};
		IN>>arr[0][0]>>arr[0][1]>>arr[0][2];
		IN>>arr[1][0]>>arr[1][1]>>arr[1][2];
		int result = 2*pow(min(5,n),3);
		int a[3] = {0};
		for (int i=0;i<3;i++) 
		{
			for (int j=0;j<min(5,n);++j) 
			{
				int x = (arr[1][i]+j-2+n)%n;
				if (check(arr[0][i],x,n))
				{
					a[i]++;
				}
			}
		}
		OUT<<result-a[0]*a[1]*a[2]<<endl;
	}
}


