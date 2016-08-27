class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int>> result;
		if(num.size()<4) return result;
		set<vector<int>> res_set;
		sort(num.begin(),num.end());
		for(int i=0;i<num.size();++i){
			for(int j=i+1;j<num.size();++j){
				int left = j+1,right = num.size()-1;
				int remain = target-num[i]-num[j];
				while(left<right){
					if(num[left]+num[right]==remain){
						vector<int> res;
						res.push_back(num[i]);
						res.push_back(num[j]);
						res.push_back(num[left]);
						res.push_back(num[right]);
						res_set.insert(res);
						++left,--right;
					}else if(num[left]+num[right]>remain){
						--right;
					}else{
						++left;
					}
				}
			}
		}
		result.insert(result.begin(),res_set.begin(),res_set.end());
		return result;
	}
};