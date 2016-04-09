#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <bitset>
using namespace std;

int find_index(vector<int> vec,int v)   //找到最后一个<=v的索引
{
	int l=0,r=vec.size()-1;
	while (l<r)
	{
		int mid = (l+r+1)/2;
		if (vec[mid]<v)
		{
			l = mid;
		}
		else
		{
			r = mid-1;
		}
	}
	if (l==r&&vec[l]<v) return l;
	return -1;
}

int longestIncrementSequence(vector<int> &seq)
{
	if (seq.size()==0) return 0;
	vector<int> maxV;
	int maxL = 1;
	maxV.push_back(seq[0]);
	int index;
	for (int i=1;i<seq.size();++i)
	{
		index = find_index(maxV,seq[i]);
		if (index!=-1)
		{
			if (index==maxV.size()-1)
			{
				maxL++;
				maxV.push_back(seq[i]);
			}
			else
			{
				maxV[index+1] = seq[i];
			}
		}
		if (maxV.size()==1&&maxV[0]>seq[i])
		{
			maxV[0] = seq[i];
		}
	}
	return maxL;
}
int main()
{
	vector<int> v;
	int n;
	while (cin>>n)
	{
		while (n--)
		{
			int m;
			cin>>m;
			v.push_back(m);
		}
		cout<<longestIncrementSequence(v)<<endl;
	}
}