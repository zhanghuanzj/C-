class Change {
public:
	int countChanges(vector<string> dic, int n, string s, string t) {
		set<string> visited;
		visited.insert(s);
		queue<string> q;
		q.push(s);
		int count = 1,new_count = 0,deepth = 1;
		while (!q.empty())
		{
			string x = q.front();
			q.pop();
			for (auto y : dic)
			{
				if (y.size()==x.size()&&visited.count(y)==0&&diffone(x,y))
				{
					if (y==t)
					{
						return deepth;
					}
					q.push(y);
					visited.insert(y);
					++new_count;
				}
			}
			count--;
			if (count==0)
			{
				count = new_count;
				new_count = 0;
				deepth++;
			}
		}
		return -1;
	}
private:
	bool diffone(const string& x,const string& y)
	{
		int count = 0;
		for (int i=0;i<x.size();++i)
		{
			if (x[i]!=y[i])
			{
				count++;
			}
		}
		return count==1;
	}
};