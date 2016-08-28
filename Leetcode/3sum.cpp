class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> result;
		sort(num.begin(),num.end());
		for(int i=0;i<num.size();++i){
			if(i>0 && num[i]==num[i-1]) continue;
			int j = i+1,k = num.size()-1;
			while(j<k){
				if(num[i]+num[j]+num[k]>0){
					--k;
				}else if(num[i]+num[j]+num[k]<0){
					++j;
				}else{
					vector<int> res;
					res.push_back(num[i]);
					res.push_back(num[j]);
					res.push_back(num[k]);
					result.push_back(res);
					do {
						++j;
					} while (j<k && num[j]==num[j-1]);
					do {
						--k;
					} while (j<k && num[k]==num[k+1]);
				}
			}
		}
		return result;
	}
};