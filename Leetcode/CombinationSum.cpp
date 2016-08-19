  class Solution {
  public:
	  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		  sort(candidates.begin(),candidates.end());
		  vector<int> combine;
		  vector<vector<int>> result;
		  solve(combine,result,candidates,0,target,0);
		  return result;
	  }
	  void solve(vector<int> &combine,vector<vector<int>> &result,vector<int> &candidates,int sum,int target,int index){
		  if(sum==target){
			  result.push_back(combine);
			  return ;
		  }else{
			  for(int i=index;i<candidates.size();++i){
				  if(sum+candidates[i]<=target){
					  combine.push_back(candidates[i]);
					  solve(combine,result,candidates,sum+candidates[i],target,i); //i表示同一个数可以多次取
					  combine.pop_back();
				  }
			  }
		  }
	  }
  };