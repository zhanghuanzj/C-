class Solution {
public:
	int totalNQueens(int n) {
		if(n<1) return 0;
		count = 0;
		vector<int> rows(n,-1);       //每行对应的列索引
		solve(0,n,rows);
		return count;
	}
	void solve(int row,int n,vector<int> &rows){
		if(row==n) {
			++count;
			return;
		}
		for(int j=0;j<n;++j){     //列
			rows[row] = j;
			if(check(rows,row,j)){
				solve(row+1,n,rows);
			}
			rows[row] = -1;
		} 
	}
	bool check(vector<int> &rows,int row,int col){           //check摆放是否可以
		for(int i=row-1;i>=0;i--){
			if(rows[i]==col||abs(col-rows[i])==row-i){   //垂直与对角线
				return false;
			}
		}
		return true;
	}
private:
	int count;
};