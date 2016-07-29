class SubMatrix {
public:
	int maxSubMatrix(vector<vector<int> > mat, int n) {
		vector<vector<pair<int,int>> > record(n,vector<pair<int,int>>(n));
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				int down = 1,right = 1;
				int x = i+1,y = j+1;
				while(y<n&&mat[i][y]==mat[i][j]){
					++y;
					++right;
				}
				while(x<n&&mat[x][j]==mat[i][j]){
					++x;
					++down;
				}
				record[i][j] = make_pair(down,right);
			}
		}
		int k = n;
		while(k){
			for(int i=0;i<=n-k;++i){
				for(int j=0;j<=n-k;++j){
					if(record[i][j].first>=k && record[i][j].second>=k &&
						record[i+k-1][j].second>=k && record[i][j+k-1].first>=k)
						return k;
				}
			}
			--k;
		}
		return 0;
	}
};