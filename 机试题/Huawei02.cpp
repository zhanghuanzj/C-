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

#define N 1020
int father[N];
void init() {
	for(int i=0; i<N; i++)
		father[i] = i;
}
// 获取根结点
int getfather(int x) {
	while(x != father[x])
		x = father[x];
	return x;
}
// 合并两个元素所在的集合
void unin(int x,int y) {
	x = getfather(x);
	y = getfather(y);
	if(x!= y)
		father[x]=y;
}
// 判断两个元素是否属于同一个集合
bool same(int x,int y) {
	return getfather(x)==getfather(y);
}


struct edge
{
	edge(int i,int j,int k):x(i),y(j),val(k){}
	int x;
	int y;
	long long val;
};

bool cmp(const edge &e1,const edge &e2)
{
	return e1.val<e2.val;
}


int main()
{
	int n;
	while (cin>>n)
	{
		//vector<vector<int>> m(n,vector<int>(n));
		init();
		vector<edge> edges;
		long long count = 0;
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<n;++j)
			{
				long long v;
				cin>>v;
				if (i<j)
				{
					edges.push_back(edge(i,j,v));
				}
			}
		}
		sort(edges.begin(),edges.end(),cmp);
		int rst = n;
		for (int i=0;i<edges.size()&&rst>1;++i)
		{
			if (!same(edges[i].x,edges[i].y))
			{
				count += edges[i].val;
				unin(edges[i].x,edges[i].y);
				--rst;
			}
		}
		cout<<count<<endl;
	}
}