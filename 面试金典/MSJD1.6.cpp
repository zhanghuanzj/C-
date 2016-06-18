class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
    	int plus = 0;
    	if (n&1)
    	{
    		plus = 1;
    	}

    	for (int i = 0; i < n/2; ++i)
    	{
    		for (int j = 0; j < n/2+plus; ++j)
    		{
    			int x = i, y = j;
    			int temp = mat[x][y];
    			for (int i = 0; i < 4; ++i)
    			{
    				temp = transform(x,y,temp,n,mat);
    			}
    		}
    	}
        return mat;
    }
    int transform(int &x,int &y,int value,int n,vector<vector<int> > &mat)
    {
    	int n_x = y;
    	int n_y = n-1-x;
    	int old_value = mat[n_x][n_y];
    	mat[n_x][n_y] = value;
    	x = n_x;
    	y = n_y;
    	return old_value;
    }
};