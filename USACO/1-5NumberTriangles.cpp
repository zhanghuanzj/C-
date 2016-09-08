/*
ID: zhanghu14
PROG: numtri
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

int main()
{
	const string path = "numtri";
	ifstream fin(path+".in");
	ofstream fout(path+".out");
	int n;
	while (IN>>n)
	{
		vector<vector<int>> arr;
		for (int i=0;i<n;++i) 
		{
			vector<int> vec(i+1);
			if (i>0)
			{
				for (int j=0;j<=i;++j) 
				{
					IN>>vec[j];
					if (j==0)
					{
						vec[j] += arr[i-1][j];
					}
					else if (j==i)
					{
						vec[j] += arr[i-1][j-1];
					}
					else
					{
						vec[j] += max(arr[i-1][j-1],arr[i-1][j]);
					}
				}
				arr.push_back(vec);
			}
			else
			{
				IN>>vec[0];
				arr.push_back(vec);
			}
		}
		int result = 0;
		for (int i=0;i<n;++i) 
		{
			result = max(arr[n-1][i],result);
		}
		OUT<<result<<endl;
	}
}


