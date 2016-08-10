class Solution {
public:
	int numDistinct(string S, string T) {
		vector<int> record(T.size()+1,0);
		record[0] = 1;
		for (int i=1;i<=S.size();++i)
		{
			for (int j=T.size();j>0;--j)
			{
				if (S[i-1]==T[j-1])
				{
					record[j] = record[j]+record[j-1];
				}
			}
		}
		return record.back();
	}
};