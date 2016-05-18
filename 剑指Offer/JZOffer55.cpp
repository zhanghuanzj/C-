class Solution
{
public:
	Solution():index(0)
	{
		for (int i = 0; i < 256; ++i)
		{		
			record.push_back(-1);
		}
	}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (record[ch]==-1)
		{
			record[ch]=index++;
		}
		else if (record[ch]>=0)
		{
			record[ch] = -2;
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int m = INT_MAX;
		char result;
		for (int i=0;i<256;++i)
		{
			if (record[i]>=0&&record[i]<m)
			{
				m = record[i];
				result = (char)i;
			}
		}
		if (m==INT_MAX)
		{
			return '#';
		}
		return result;
	}
	vector<int> record;
	int index;
};