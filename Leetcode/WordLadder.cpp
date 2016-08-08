class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		if (start==end)
		{
			return 1;
		}
		queue<string> words;
		words.push(start);
		dict.erase(start);
		int depth = 1;
		int remain = 1;
		int newRemain = 0;
		while (!words.empty())
		{
			string word = words.front();
			words.pop();
			for (auto it = dict.begin();it!=dict.end();)
			{
				if (isDiffOne(word,*it))
				{
					if (*it==end)
					{
						return depth+1;
					}
					else
					{
						words.push(*it);
						it = dict.erase(it);
						++newRemain;
					}
				}
				else
				{
					++it;
				}
			}
			--remain;
			if (remain==0)
			{
				remain = newRemain;
				newRemain = 0;
				++depth;
			}
		}
		return 0;
	}
private:
	bool isDiffOne(const string &s1,const string &s2)
	{
		int count = 0;
		for (int i=0;i<s1.size();++i)
		{
			if (s1[i]!=s2[i])
			{
				++count;
			}
		}
		return count==1;
	}
};