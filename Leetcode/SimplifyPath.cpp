 class Solution {
 public:
	 string simplifyPath(string path) {
		 vector<string> str = split(path,'/');
		 stack<string> s;
		 for (int i=0;i<str.size();++i){
			 if (str[i].empty()||str[i]==".") continue;
			 else if (str[i]==".."){
				 if (!s.empty()){
				 	s.pop();
				 }
			 }else{
				 s.push(str[i]);
			 }
		 }
		 string result;
		 while (!s.empty()){
			 result = "/"+s.top()+result;
			 s.pop();
		 }
		 return result.empty()?"/":result;
	 }
	 vector<string> split(string s,char c) {
		 vector<string> str;
		 s = s+"//";
		 int pre = 0;
		 for (int i=0;i<s.size();++i) {
			 if (s[i]=='/') {
				 str.push_back(s.substr(pre,i-pre));
				 pre = i+1;
			 }
		 }
		 return str;
	 }
 };