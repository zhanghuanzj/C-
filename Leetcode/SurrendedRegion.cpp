class Solution {
public:
	void solve(vector<vector<char>> &board) {
		int n = board.size();
		if (n==0) {
			return;
		}
		int m = board.front().size();
		for (int i=0;i<n;++i){
			for (int j=0;j<m;++j){
				if ((board[i][j]=='O') && (i==0||i==n-1||j==0||j==m-1)){
					dfs(board,i,j);
				}
			}
		}
		for (int i=0;i<n;++i){
			for (int j=0;j<m;++j){
				if (board[i][j]=='O'){
					board[i][j] = 'X';
				}else if (board[i][j]=='T'){
					board[i][j] = 'O';
				}
			}
		}
	}
private:
	void dfs(vector<vector<char>> &board,int x,int y){
		board[x][y] = 'T';
		int dx[] = {1,-1,0,0};
		int dy[] = {0,0,-1,1};
		for (int i=0;i<4;++i){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if ((nx>=0&&nx<board.size()&&ny>=0&&ny<board.front().size())&&board[nx][ny]=='O'){
				dfs(board,nx,ny);
			}
		}
	}
};