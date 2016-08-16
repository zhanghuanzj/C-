 class Solution {
 public:
	 void setZeroes(vector<vector<int> > &matrix) {
		 if(matrix.empty()) return;
		 int m = matrix.size();
		 int n = matrix.front().size();
		 bool right = false,down = false;
		 for(int i=0;i<m;++i){
			 for(int j=0;j<n;++j){
				 if(matrix[i][j]==0){
					 if (j==0) down = true;
					 if (i==0) right = true;
					 matrix[i][0] = 0;
					 matrix[0][j] = 0;
				 }
			 }
		 }
		 for(int i=1;i<m;++i){
			 if(matrix[i][0]==0){
				 fill_n(matrix[i].begin(),n,0);
			 }
		 }
		 for(int i=1;i<n;++i){
			 if(matrix[0][i]==0){
				 for (int j=1;j<m;++j)
					matrix[j][i] = 0;
			 }
		 }
		 if (right) fill_n(matrix[0].begin(),n,0);
		 if(down) {
			 for (int j=1;j<m;++j)
				 matrix[j][0] = 0;
		 }
	 }
 };