/*
ID: zhanghu14
PROG: friday
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <unordered_set>
using namespace std;

int months[2][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

bool isLeapYear(int n)
{
	if ((n%4==0&&n%100!=0)||n%400==0)
	{
		return true;
	}
	return false;
}

int main()
{
	const string path = "friday";
	ifstream fin(path+".in");
	ofstream fout(path+".out");
	int n;
	while (fin>>n)
	{
		vector<int> result(7,0);
		int week = 0;
		for (int i=0;i<n;++i)
		{
			int index = 0;
			if (isLeapYear(i+1900))
			{
				++index;
			}
			for (int j=0;j<12;++j)
			{
				++result[(week+12)%7];
				week = (week+months[index][j])%7;
			}
		}
		fout<<result[5]<<" "<<result[6]<<" "<<result[0]<<" "<<result[1]<<" "<<result[2]<<" "<<result[3]<<" "<<result[4]<<endl;
	}
}

 
