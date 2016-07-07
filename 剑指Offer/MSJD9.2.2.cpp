class Robot {
public:
    int countWays(vector<vector<int> > map, int x, int y) {
        vector<vector<unsigned int> > record(x,vector<unsigned int>(y));
        bool isBlock = false;
        for (int i = 0; i < y; ++i)
        {
        	if (map[0][i]!=1)
        	{
        		isBlock = true;
        	}
        	record[0][i] = isBlock?0:1;
        }
        isBlock = false;
        for (int i = 0; i < x; ++i)
        {
        	if (map[i][0]!=1)
        	{
        		isBlock = true;
        	}
        	record[i][0] = isBlock?0:1;
        }
        for (int i = 1; i < x; ++i)
        {
        	for (int j = 1; j < y; ++j)
        	{
        		record[i][j] = (map[i][j]==1)?((record[i][j-1]+record[i-1][j])%1000000007):0;
        	}
        }
        return record[x-1][y-1];
    }
};
