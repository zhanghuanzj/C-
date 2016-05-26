#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
#include <sstream>
using namespace std;

bool isDead(int x,int y,int z,vector<vector<int>> &m)
{
	vector<vector<bool>> visited(10,vector<bool>(10));
	int op = 1;
	if (z==1)
	{
		op = 2;
	}
	int px[] = {1,-1,0,0};
	int py[] = {0,0,1,-1};
	visited[x][y] = true;
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	while (!q.empty())
	{
		pair<int,int> p = q.front();
		q.pop();
		for (int i=0;i<4;++i)
		{
			int tempx = p.first+px[i];
			int tempy = p.second+py[i];
			if (tempx>=0&&tempx<10&&tempy>=0&&tempy<10)
			{
				if (!visited[tempx][tempy])//未访问过
				{
					visited[tempx][tempy] = true;
					if (m[tempx][tempy]==0) //空
					{
						return false;
					}
					else if (m[tempx][tempy]==z)
					{
						q.push(make_pair(tempx,tempy));
					}
				}
			}
		}
	}
	return true;
}

int flip(int x,int y,int z,vector<vector<int>> &m)
{
	int count = 0;
	vector<vector<bool>> visited(10,vector<bool>(10));
	int op = 1;
	if (z==1)
	{
		op = 2;
	}
	int px[] = {1,-1,0,0};
	int py[] = {0,0,1,-1};
	visited[x][y] = true;
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	while (!q.empty())
	{
		pair<int,int> p = q.front();
		q.pop();
		m[p.first][p.second] = 0;      //去子
		++count;
		for (int i=0;i<4;++i)
		{
			int tempx = p.first+px[i];
			int tempy = p.second+py[i];
			if (tempx>=0&&tempx<10&&tempy>=0&&tempy<10)
			{
				if (!visited[tempx][tempy])//未访问过
				{
					visited[tempx][tempy] = true;
					if (m[tempx][tempy]==z)
					{
						q.push(make_pair(tempx,tempy));
					}
				}
			}
		}
	}
	return count;
}
int main()
{
	vector<vector<int>> m(10,vector<int>(10));
	for (int i=0;i<10;++i)
	{
		for (int j=0;j<10;++j)
		{
			cin>>m[i][j];
		}
	}
	int x,y,z;
	while (cin>>x>>y>>z)
	{
		int op = 1;
		if (z==1)
		{
			op = 2;
		}
		if (m[x][y]==1||m[x][y]==2)
		{
			cout<<2147483647<<endl;
			continue;
		}
		m[x][y] = z;
		bool isError = false;
		for (int i=0;i<10;++i)
		{
			for (int j=0;j<10;++j)
			{
				if (m[i][j]==z&&isDead(i,j,z,m))
				{
					isError = true;   //自己可能会自杀
				}
			}
		}
		int sum = 0;
		for (int i=0;i<10;++i)
		{
			for (int j=0;j<10;++j)
			{
				if (m[i][j]==op&&isDead(i,j,op,m))  //会令对方死棋,便不再是自杀
				{
					isError = false;
					sum += flip(i,j,op,m);
				}
			}
		}
		if (isError)
		{
			cout<<2147483647<<endl;
			continue;
		}
		if (sum&&op==2)
		{
			sum = -sum;
		}
		cout<<sum<<endl;
	}

}