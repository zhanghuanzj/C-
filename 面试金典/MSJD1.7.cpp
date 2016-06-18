class Clearer {
public:
	vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
		bitset<300> row(0U);
		bitset<300> column(0U);
		for (int i=0;i<mat.size();++i)
		{
			for (int j=0;j<n;++j)
			{
				if (mat[i][j]==0)
				{
					row.set(i);
					column.set(j);
				}
			}
		}
		for (int i=0;i<mat.size();++i)
		{
			for (int j=0;j<n;++j)
			{
				if (row.test(i)||column.test(j))
				{
					mat[i][j]=0;
					
				}
			}
		}
		return mat;
	}
};