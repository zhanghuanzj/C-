/*
ID: zhanghu14
PROG: milk3
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

int a,b,c;
set<int> result;
int move_to(int x,int y,int volume) //x->y
{
	if (x > volume-y)
	{
		return volume-y;
	}
	else
	{
		return x;
	}
}
void dfs(int A,int B,int C,vector<vector<vector<bool>>> &visited)
{
	if (visited[A][B][C])
	{
		return;
	}
	visited[A][B][C] = true;
	if (A==0)
	{
		result.insert(C);
	}
	int pour;
	//A->B
	pour = move_to(A,B,b);
	dfs(A-pour,B+pour,C,visited);
	//B->A
	pour = move_to(B,A,a);
	dfs(A+pour,B-pour,C,visited);
	//C->B
	pour = move_to(C,B,b);
	dfs(A,B+pour,C-pour,visited);
	//B->C
	pour = move_to(B,C,c);
	dfs(A,B-pour,C+pour,visited);
	//A->C
	pour = move_to(A,C,c);
	dfs(A-pour,B,C+pour,visited);
	//C->A
	pour = move_to(C,A,a);
	dfs(A+pour,B,C-pour,visited);
}
int main()
{
	const string path = "milk3";
	ifstream fin(path+".in");
	ofstream fout(path+".out");

	while (IN>>a>>b>>c)
	{
		vector<vector<vector<bool>>> visited(a+1,vector<vector<bool>>(b+1,vector<bool>(c+1,false)));
		result.clear();
		dfs(0,0,c,visited);
		int index = 0;
		for (auto v : result) 
		{
			if (index==result.size()-1)
			{
				OUT<<v;
			}
			else
			{
				OUT<<v<<" ";
			}
			++index;
		}
		OUT<<endl;
	}
}


