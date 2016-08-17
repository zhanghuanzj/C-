 class Solution {
 public:
	 vector<vector<int> > generateMatrix(int n) {
		 vector<vector<int>> m(n,vector<int>(n));
		 int dx[] = {0,1,0,-1};
		 int dy[] = {1,0,-1,0};
		 int x = n, y = n,num = 1,dir = 0;
		 int px = 0,py = -1;
		 while(x>0||y>0){
			 if(dir&1){
				 for(int i=0;i<y;++i){
					 px += dx[dir];
					 py += dy[dir];
					 m[px][py] = num++;
				 }
				 --x;
			 }else{
				 for(int i=0;i<x;++i){
					 px += dx[dir];
					 py += dy[dir];
					 m[px][py] = num++;
				 }
				 --y;
			 }
			 dir = (dir+1)%4;
		 }
		 return m;
	 }
 };