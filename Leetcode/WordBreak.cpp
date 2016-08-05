class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty())
		{
			return false;
		}
		vector<bool> indics(s.size(),false);
		for(int i=1;i<=s.size();++i){
			for(int pre=0;pre<i;++pre){
				if(((pre==0)||indics[pre-1])&&dict.count(s.substr(pre,i-pre))){
					indics[i-1] =true;
				}
			}
		}
		return indics.back();
	}
};