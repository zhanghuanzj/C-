class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		vector<int> record(256);
		for(auto c:str)
		{
			record[c]++;
		}
		for (int i=0;i<str.size();++i)
		{
			if (record[str[i]]==1)
			{
				return i;
			}
		}
		return -1;
	}
};