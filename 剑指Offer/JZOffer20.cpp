class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result;
		if (matrix.empty()||matrix.front().empty())
		{
			return result;
		}
		int n = matrix.size();
		int m = matrix[0].size();
		int size = m*n;
		int px[] = {0,1,0,-1};
		int py[] = {1,0,-1,0};
		int x = 0,y = -1;
		int dir = 0;
		int count = 0;
		while(count<size)
		{
			int k = 0;
			if (dir&1)
			{
				k = n;
				--m;
			}
			else
			{
				k = m;
				--n;
			}
			while(k--)
			{
				x += px[dir];
				y += py[dir];
				++count;
				result.push_back(matrix[x][y]);
			}
			dir = (dir+1)%4;
		}
		return result;
	}
};