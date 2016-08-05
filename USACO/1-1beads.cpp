/*
ID: zhanghu14
PROG: beads
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <unordered_set>
using namespace std;


int main()
{
	const string path = "beads";
	ifstream fin(path+".in");
	ofstream fout(path+".out");
	int n;
	while (fin>>n)
	{
		string s;
		fin>>s;
		s = s+s;
		int result = 0;
		for (int i=0;i<n;)
		{
			int left = i-1 , right = i;
			int leftCount = 0, rightCount = 0;
			char leftColor = 'w',rightColor = 'w';
			while (left>=0)
			{
				if (s[left]=='w')
				{
					leftCount++;
				}
				else if (s[left]!='w')
				{
					if (leftColor=='w')
					{
						leftColor = s[left];
						leftCount++;
					}
					else if (leftColor==s[left])
					{
						leftCount++;
					}
					else
					{
						break;
					}
				}
				--left;
			}
			while (right<s.size())
			{
				if (s[right]=='w')
				{
					rightCount++;
				}
				else if (s[right]!='w')
				{
					if (rightColor=='w')
					{
						rightColor = s[right];
						rightCount++;
					}
					else if (rightColor==s[right])
					{
						rightCount++;
					}
					else
					{
						break;
					}
				}
				++right;
			}
			result = max(result,leftCount+rightCount);
			while (i+1<n&&(s[i+1]=='w'||s[i+1]==s[i]))
			{
				++i;
			}
			++i;
		}
		if (result>n)
		{
			result = n;
		}
		fout<<result<<endl;
	}
}

 