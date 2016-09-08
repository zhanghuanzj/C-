/*
ID: zhanghu14
PROG: pprime
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

bool isPrime(int v)
{
	int bound = sqrt(v);
	for (int i=2;i<=bound;++i) 
	{
		if (v%i==0)
		{
			return false;
		}
	}
	return true;
}
int getPalindrome(int n)
{
	int v = n/10;
	while (v)
	{
		n = n*10 + v%10;
		v /= 10;
	}
	return n;
}

void initPalindrome(vector<int> &palindrome)
{
	for (int i=5;i<10;++i) 
	{
		palindrome.push_back(i);
	}
	palindrome.push_back(11);
	for(int i=10;i<10000;++i)
	{
		palindrome.push_back(getPalindrome(i));
	}
}
int main()
{
	const string path = "pprime";
	ifstream fin(path+".in");
	ofstream fout(path+".out");

	vector<int> palindrome;
	initPalindrome(palindrome);
	int a,b;
	while (IN>>a>>b)
	{
		auto it1 = lower_bound(palindrome.begin(),palindrome.end(),a);
		auto it2 = upper_bound(palindrome.begin(),palindrome.end(),b);
		while (it1!=it2)
		{
			if (isPrime(*it1))
			{
				OUT<<*it1<<endl;
			}
			++it1;
		}
	}
}


