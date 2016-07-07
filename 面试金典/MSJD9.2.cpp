class Robot {
public:
    int countWays(int x, int y) {
        vector<vector<int>> m(x,vector<int>(y));
        for (int i = 0; i < y; ++i)
        {
        	m[0][i] = 1;
        }
        for (int i = 0; i < x; ++i)
        {
        	m[i][0] = 1;
        }
        for (int i = 1; i < x; ++i)
        {
        	for (int j = 1; j < y; ++j)
        	{
        		m[i][j] = m[i-1][j]+m[i][j-1];
        	}
        }
        return m[x-1][y-1];
    }
};