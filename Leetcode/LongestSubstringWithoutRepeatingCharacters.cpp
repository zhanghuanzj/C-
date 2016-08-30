class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> record(26,0);
		int left = 0;
		int maxLen = 0;
		for(int i=0;i<s.size();++i){
			int index = s[i]-'a';
			++record[index];
			if(record[index]==1){
				maxLen = max(maxLen,i-left+1);
			} else{
				while(record[index]>1){
					--record[s[left++]-'a'];
				}
			}
		}
		return maxLen;
	}
};