class Flood {
public:
    int floodFill(vector<vector<int> > map, int n, int m) {
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int i=0;i<4;++i){
                int x = p.first + dx[i];
                int y = p.second + dy[i];
                if(x>=0&&x<map.size()&&y>=0&&y<map.front().size()&&map[x][y]==0){
                    map[x][y] = map[p.first][p.second] + 1;
                    if(x==n-1&&y==m-1) return map[x][y];
                    q.push(make_pair(x,y));
                }
            }
        }
        return map[n-1][m-1];
    }
};