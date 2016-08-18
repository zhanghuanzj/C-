class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		if(n<1) return vector<vector<string>>();
		vector<vector<int>> solves;
		vector<vector<string>> result;
		vector<int> rows(n,-1);       //每行对应的列索引
		solve(solves,0,n,rows);
		fillQueens(solves,result,n);
		return result;
	}
	void solve(vector<vector<int>> &solves,int row,int n,vector<int> &rows){
		if(row==n) {
			solves.push_back(rows);
			return;
		}
		for(int j=0;j<n;++j){     //列
			rows[row] = j;
			if(check(rows,row,j)){
				solve(solves,row+1,n,rows);
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
	void fillQueens(vector<vector<int>>& solves,vector<vector<string>>& result,int n){
		for(int i=0;i<solves.size();++i){
			vector<string> board(n,string(n,'.'));
			for(int j=0;j<n;++j){
				board[j][solves[i][j]] = 'Q';
			}
			result.push_back(board);
		}
	}
};