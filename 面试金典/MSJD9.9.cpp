class Queens {
public:
	int count;
	int size;
	int nQueens(int n) {
		count = 0;
		size = n;
		vector<int> column(n,-1);
		solve(0,column);
		return count;
	}

	void solve(int row,vector<int>& column){
		if(row==size) count++;
		else{
			for(int i=0;i<size;++i){
				if(check(row,i,column)){
					column[i] = row;
					solve(row+1,column);
					column[i] = -1;
				}
			}
		}
	}

	bool check(int row,int col,vector<int>& column){
		if(column[col] != -1) return false;
		int r = row-1;
		int lc = col-1;
		int rc = col+1;
		while(r>=0){
			if(lc>=0&&column[lc]==r) return false;
			if(rc<size&&column[rc]==r) return false;
			--r,--lc,++rc;
		}
		return true;
	}
};