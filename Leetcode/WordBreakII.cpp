class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<unordered_set<int>> record(s.size());
		for(int i=0;i<s.size();++i){
			for(int j=i+1;j<=s.size();++j){
				if(dict.count(s.substr(i,j-i))){
					record[j-1].insert(i);
				}
			}
		}
		vector<string> result;
		string temp;
		getString(s,record,s.size(),temp,result);
		return result;
	}
	void getString(const string &s,vector<unordered_set<int>>& record,int index,string &pre,vector<string>& result){
		for(auto i : record[index-1]){
			string sub = s.substr(i,index-i);
			if(i==0){
				if (pre.empty()){
					result.push_back(sub);
				}
				else{
					result.push_back(sub+" "+pre);
				}	
			}else{
				string temp = sub;
				if (!pre.empty()){
					temp = sub + " " +pre;
				}	
				getString(s,record,i,temp,result);
			}
		}
	}
};