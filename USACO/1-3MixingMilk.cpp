/*
ID: zhanghu14
PROG: milk
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

struct Farmer
{
	int price;
	int amount;
};
bool comp(const Farmer& f1,const Farmer& f2){
	return f1.price<f2.price;
}
int main()
{
	const string path = "milk";
	ifstream fin(path+".in");
	ofstream fout(path+".out");
	
	int m,n;
	while (IN>>m>>n)
	{
		vector<Farmer> farmers(n);
		for (int i=0;i<n;++i) {
			IN>>farmers[i].price>>farmers[i].amount;
		}
		sort(farmers.begin(),farmers.end(),comp);
		int money = 0;
		for (int i=0;i<m&&m>0;++i) {
			if (farmers[i].amount<=m){
				m -= farmers[i].amount;
				money += farmers[i].amount*farmers[i].price;
			}else{
				money += farmers[i].price*m;
				m = 0;
			}
		}
		OUT<<money<<endl;
	}
}


