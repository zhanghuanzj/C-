  class Solution {
  public:
	  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		  sort(num.begin(),num.end());
		  vector<int> combine;
		  vector<vector<int>> result;
		  solve(combine,result,num,0,target,0);
		  return result;
	  }
	  void solve(vector<int> &combine,vector<vector<int>> &result,vector<int> &candidates,int sum,int target,int index){
		  if(sum==target){
			  result.push_back(combine);
			  return ;
		  }else{
			  for(int i=index;i<candidates.size();++i){
				  if(sum+candidates[i]<=target){
					  if(i==index || candidates[i]!=candidates[i-1]){
						  combine.push_back(candidates[i]);
						  solve(combine,result,candidates,sum+candidates[i],target,i+1);
						  combine.pop_back();
					  } //第一次可以，第二次有重复
				  }
			  }
		  }
	  }
};