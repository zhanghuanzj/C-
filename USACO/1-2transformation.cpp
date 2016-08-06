/*
ID: zhanghu14
PROG: transform
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool isEqual(const vector<vector<char>> &square1,const vector<vector<char>> &square2)
{
	for (int i=0;i<square1.size();++i)
	{
		for (int j=0;j<square1.front().size();++j)
		{
			if (square1[i][j] != square2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

vector<vector<char>> rotate(const vector<vector<char>> &square)
{
	vector<vector<char>> result(square.size(),vector<char>(square.size()));
	int n = square.size()-1;
	for (int i=0;i<square.size();++i)
	{
		for (int j=0;j<square.front().size();++j)
		{
			result[j][n-i] = square[i][j];
		}
	}
	return result;
}

vector<vector<char>> reflection(const vector<vector<char>> &square)
{
	vector<vector<char>> result(square.size(),vector<char>(square.size()));
	int n = square.size()-1;
	for (int i=0;i<square.size();++i)
	{
		for (int j=0;j<square.front().size();++j)
		{
			result[i][n-j] = square[i][j];
		}
	}
	return result;
}

int main()
{
	const string path = "transform";
	ifstream fin(path+".in");
	ofstream fout(path+".out");

	int n;
	while (fin>>n)
	{
		vector<vector<char>> before(n,vector<char>(n));
		vector<vector<char>> after(n,vector<char>(n));
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<n;++j)
			{
				fin>>before[i][j];
			}
		}
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<n;++j)
			{
				fin>>after[i][j];
			}
		}
		int change = 7;
		if (isEqual(rotate(before),after))
		{
			change = 1;
		}
		else if (isEqual(rotate(rotate(before)),after))
		{
			change = 2;
		}
		else if (isEqual(rotate(rotate(rotate(before))),after))
		{
			change = 3;
		}
		else if (isEqual(reflection(before),after))
		{
			change = 4;
		}
		else if (isEqual(rotate(reflection(before)),after) || 
			isEqual(rotate(rotate(reflection(before))),after) ||
			isEqual(rotate(rotate(rotate(reflection(before)))),after))
		{
			change = 5;
		}
		else if (isEqual(before,after))
		{
			change = 6;
		}
		fout<<change<<endl;
	}
	
}


