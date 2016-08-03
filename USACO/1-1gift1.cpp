/*
ID: zhanghu14
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	const string path = "gift1";
	ifstream fin(path+".in");
	ofstream fout(path+".out");
	int n;
	while (fin>>n)
	{
		map<string,int> record;
		vector<string> names(n);
		vector<int> momey(n,0);
		for (int i=0;i<n;++i)
		{
			string s;
			fin>>s;
			record[s] = i;
			names[i] = s;
		}
		string name;
		int sum,count;
		while(fin>>name>>sum>>count)
		{
			for (int j=0;j<count;++j)
			{
				string s;
				fin>>s;
				int index1 = record[s];
				int index2 = record[name];
				momey[index1] += sum/count;
				momey[index2] -= sum/count;
			}
		}
		for (int i=0;i<n;++i)
		{
			fout<<names[i]<<" "<<momey[i]<<endl;
		}
	}
}

 