class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.empty()){
			return "";
		}
		string prefix = strs.front();
		int size = prefix.size();
		for(int i=1;i<strs.size();++i){
			size = min(size,(int)strs[i].size());
			string s = strs[i];
			for(int j=0;j<size;++j){
				if(prefix[j] != s[j]){
					size = j;
					break;
				}
			}
		}
		return prefix.substr(0,size);
	}
};