class Solution {
public:
	int minCut(string s) {
		int len = s.size();
		vector<int> cuts(len+1);
		for (int i=0;i<=len;++i)
		{
			cuts[i] = len-i;
		}
		vector<vector<bool>> dp(len,vector<bool>(len,false));
		for (int i=len-1;i>=0;--i)
		{
			for (int j=i;j<len;++j)
			{
				if ( s[i]==s[j] && ( j-i<2 || dp[i+1][j-1]) )
				{
					dp[i][j] = true;
					cuts[i] = min(cuts[i],cuts[j+1]+1);
				}
			}
		}
		return cuts[0]-1;
	}
};