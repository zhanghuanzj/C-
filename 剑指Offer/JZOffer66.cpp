class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix==NULL||rows<1||cols<1||str==NULL)
		{
			return false;
		}
		vector<vector<bool>> visited(rows,vector<bool>(cols));
		for(int i=0;i<rows;++i)
		{
			for(int j=0;j<cols;++j)
			{
				if (solve(matrix,rows,cols,i,j,str,0,visited))
				{
					return true;
				}
			}
		}
		return false;
	}

	bool solve(char *matrix,int rows,int cols,int m,int n,char *str,int index,vector<vector<bool>> &visited)
	{
		int x[] = {1,-1,0,0};
		int y[] = {0,0,-1,1};
		if (str[index]=='\0')
		{
			return true;
		}
		if (m>=0&&m<rows&&n>=0&&n<cols&&!visited[m][n]&&str[index]==matrix[m*cols+n])		
		{
			visited[m][n] = true;
			for (int i = 0; i < 4; ++i)
			{
				if (solve(matrix,rows,cols,m+x[i],n+y[i],str,index+1,visited))
				{
					return true;
				}
			}
			visited[m][n] = false;
		}
		return false;
	}

};