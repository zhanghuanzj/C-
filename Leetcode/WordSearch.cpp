class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty()) return false;
        if(word.empty()) return true;
        int m = board.size();
        int n = board.front().size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]==word[0]&&dfs(board,visited,i,j,1,word)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(const vector<vector<char> > &board,vector<vector<bool>> &visited,int x,int y,int n,const string& word){
        if(n==word.size()) return true;
        visited[x][y] = true;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        for(int i=0;i<4;++i){
            int px = x+dx[i];
            int py = y+dy[i];
            if(px>=0&&px<board.size()&&py>=0&&py<board.front().size()&&word[n]==board[px][py]&&!visited[px][py]){
                if(dfs(board,visited,px,py,n+1,word)){
                    return true;
                }
            }
        }
        visited[x][y] = false;
        return false;
    }
};