 class Solution {
 public:
	 int maximalRectangle(vector<vector<char> > &matrix) {
		 if(matrix.empty()) return 0;
		 int m = matrix.size();
		 int n = matrix.front().size();
		 int result = 0;
		 vector<int> arr(n,0);
		 for(int i=0;i<m;++i){
			 for(int j=0;j<n;++j){
				 if(matrix[i][j]=='0'){
					 arr[j] = 0;
				 }else{
					 arr[j]++;
				 }
			 }
			 result = max(result,solve(arr));
		 }
		 return result;
	 } 
	 int solve(vector<int> &arr){
		 int result = 0;
		 stack<int> s;
		 for(auto v : arr){
			 int count = 1;
			 while(!s.empty() && s.top()>v){
				 result = max(result,s.top()*count);
				 ++count;
				 s.pop();
			 }
			 for(int i=0;i<count;++i)
				 s.push(v); 
		 }
		 int count = 1;
		 while (!s.empty())
		 {
			 result = max(result,s.top()*count);
			 ++count;
			 s.pop();
		 }
		 return result;
	 }
 };