class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		dict.insert(end);
		dict.erase(start);
		unordered_map<string,unordered_set<string>> record;
		vector<vector<string>> result;
		unordered_set<string> cur;
		unordered_set<string> next;
		cur.insert(start);
		while (!cur.empty())
		{
			for (auto word : cur)
			{
				for (int i=0;i<word.size();++i)
				{
					for (int j=0;j<26;++j)
					{		
						string temp = word;
						temp[i] = 'a'+j;
						if (dict.find(temp)!=dict.end())
						{
							next.insert(temp);
							record[temp].insert(word);   //反存
						}
					}
				}
			}
			cur = next;
			next.clear();
			for (auto word : cur)
			{
				dict.erase(word);
				if (word==end)
				{
					vector<string> path;
					getPaths(record,end,start,result,path);
					break;
				}
			}
		}
		for (auto& path:result)
		{
			reverse(path.begin(),path.end());
		}
		return result;
	}
private:
	void getPaths(const unordered_map<string,unordered_set<string>> &record,const string &start,const string &end,vector<vector<string>> &result,vector<string> &path)
	{
		path.push_back(start);
		if (start==end)
		{
			result.push_back(path);
			path.pop_back();
			return;
		}
		for (auto word : record.at(start))
		{
			getPaths(record,word,end,result,path);
		}
		path.pop_back();
	}
};