class Coins {
public:
	int countWays(int n) {
		int coin[4] = {1,5,10,25};
		int record[100002] = {0};
		//vector<vector<int>> record(4,vector<int>(n+1));
		record[0] = 1;
		for (int i=0;i<4;++i)
		{
			for (int j=coin[i];j<=n;++j)
			{
				record[j] = (record[j]+record[j-coin[i]])%1000000007;
			}
		}
		return record[n];
	}
};