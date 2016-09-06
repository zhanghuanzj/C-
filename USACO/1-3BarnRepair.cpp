/*
ID: zhanghu14
PROG: barn1
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
	const string path = "barn1";
	ifstream fin(path+".in");
	ofstream fout(path+".out");
	
	int m,s,c;
	while (IN>>m>>s>>c)
	{
		vector<int> num(c,0);
		vector<int> stalls;
		for (int i=0;i<c;++i) {	
			IN>>num[i];
		}
		sort(num.begin(),num.end());
		for (int i=0;i<c-1;++i) {
			if (num[i]+1<num[i+1]){
				stalls.push_back(num[i+1]-num[i]-1);
			}
		}
		sort(stalls.begin(),stalls.end());
		int result = c;
		for (int i=0;i<(int)(stalls.size()+1-m);++i) {
			result += stalls[i];
		}
		OUT<<result<<endl;
	}
}


