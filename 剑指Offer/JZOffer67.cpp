class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold<0||rows<1||cols<1)
		{
			return 0;
		}
		vector<vector<bool>> visited(rows,vector<bool>(cols));
		return solve(threshold,0,0,visited,rows,cols);
	}
	int solve(int threshold,int m,int n,vector<vector<bool>>& visited,int rows,int cols)
	{
		int count = 0;
		if (m<rows&&n<cols&&isOK(m,n,threshold,visited))
		{
			++count;
			visited[m][n] = true;
			count += solve(threshold,m,n+1,visited,rows,cols)+solve(threshold,m+1,n,visited,rows,cols);
		}
		return count;
	}
	bool isOK(int m,int n,int threshold,vector<vector<bool>>& visited)
	{
		int sum = 0;
		bool flag = visited[m][n];
		while(m)
		{
			sum += m%10;
			m /= 10;
		}
		while(n)
		{
			sum += n%10;
			n /= 10;
		}
		return sum<=threshold&&!flag;
	}
};