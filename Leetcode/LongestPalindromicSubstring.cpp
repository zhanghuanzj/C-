class Solution {
public:
	string longestPalindrome(string s) {
		string str = init(s);
		vector<int> p = getP(str);
		int index = 0;
		int len = 1;
		for(int i=1;i<p.size();++i){
			if(p[i]>len){
				index = i;
				len = p[i];
			}
		}
		index = (index-len+2)/2-1;
		return s.substr(index,len-1);
	}
	string init(string s){
		string str = "#";
		for(auto c : s){
			str = str + c +"#";
		}
		return "$"+str+"&";
	}
	vector<int> getP(string str){
		vector<int> p(str.size(),1);
		int boundary = 0;
		int currentCenter = 0;
		for(int i=1;i<str.size()-1;++i){
			if(boundary>i){
				p[i] = min(p[2*currentCenter-i],boundary-i);
			}
			while(str[i-p[i]]==str[i+p[i]]) ++p[i];
			if(i+p[i]>boundary){
				boundary = i+p[i];
				currentCenter = i;
			}
		}
		return p;
	}
};