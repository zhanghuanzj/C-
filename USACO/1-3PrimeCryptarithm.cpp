/*
ID: zhanghu14
PROG: crypt1
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

bool check(const vector<bool> &hash,int num)
{
	while (num)
	{
		if (!hash[num%10])
		{
			return false;
		}
		num /= 10;
	}
	return true;
}
int main()
{
	const string path = "crypt1";
	ifstream fin(path+".in");
	ofstream fout(path+".out");
	
	int n;
	while (IN>>n)
	{
		vector<bool> hash(10,false);
		int count = 0;
		for (int i=0;i<n;++i) 
		{
			int num;
			IN>>num;
			hash[num] = true;
		}
		for (int i=100;i<1000;++i) 
		{
			if (check(hash,i))
			{
				for (int j=10;j<100;++j) 
				{
					if (check(hash,j)&&i*j<10000&&i*(j%10)<1000&&i*(j/10)<1000&&check(hash,i*(j%10))&&check(hash,i*(j/10))&&check(hash,i*j))
					{
						++count;
					}
				}
			}
		}
		OUT<<count<<endl;
	}
}


