class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int,int> hash;
		vector<int> result;
		for(int i=0;i<numbers.size();++i){
			int value = target - numbers[i];
			if(hash.find(value)!=hash.end()){
				result.push_back(hash[value]);
				result.push_back(i+1);
				return result;
			}
			hash[numbers[i]] = i+1;
		}
		return result;
	}
};