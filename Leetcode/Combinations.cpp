 class Solution {
 public:
	 vector<vector<int> > combine(int n, int k) {
		 vector<int> path;
		 vector<vector<int>> result;
		 solve(1,n,k,result,path);
		 return result;
	 }
	 void solve(int left,int right,int k,vector<vector<int>> &result,vector<int>&path){
		 if(right-left+1<k) return;
		 if (k==0)
		 {
			 result.push_back(path);
		 }else if(right-left+1==k){
			 for(int i=left;i<=right;++i){
				 path.push_back(i);
			 }
			 result.push_back(path);
			 for(int i=left;i<=right;++i){
				 path.pop_back();
			 }
		 }else{
			 for(int i=left;i<=right-k+1;++i){
				 path.push_back(i);
				 solve(i+1,right,k-1,result,path);
				 path.pop_back();
			 }
		 }
	 }
 };
