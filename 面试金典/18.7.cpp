bool comp(const string& s1,const string& s2){
	return s1.size()<s2.size();
}

class LongestString {
private:
	set<string> record;
public:

	int getLongest(vector<string> str, int n) {
		record.clear();
		for(auto s : str){
			record.insert(s);
		}
		sort(str.begin(),str.end(),comp);
		int result = 0;
		for(int i=str.size()-1;i>=0;i--){
			if(check(str[i],true)){
				return str[i].size();
			}
		}
		return -1;
	}
	bool check(const string& s,bool isOri){
		if(s==""||(s.size()==1&&record.find(s)==record.end())) return false;
		if(record.find(s)!=record.end()&&!isOri) return true;
		for(int i=1;i<=s.size()-1;++i){
			string left = s.substr(0,i);
			string right = s.substr(i,s.size());
			if(check(left,false)&&check(right,false)) return true;
		}
		return false;
	}
};