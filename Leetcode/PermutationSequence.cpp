 class Solution {
 public:
	 string getPermutation(int n, int k) {
		 if(n<1||k<1) return "";
		 string s;
		 for(int i=1;i<=n;++i) s += to_string(i);
		 for (int i=1;i<k;++i) {
			 nextPermutation(s);
		 }
		 return s;
	 }
	 void nextPermutation(string &s){
		 int i=s.size()-1;
		 while(i>0&&s[i]<s[i-1]) --i;
		 if(i==0){
			 reverse(s.begin(),s.end());
			 return;
		 }else{
			 int j = s.size()-1;
			 while(j>0&&s[j]<s[i-1]) --j;
			 swap(s[i-1],s[j]);
			 reverse(s.begin()+i,s.end());
		 } 
	 }
 };