string s[10] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		solve(digits,result,"",0);
		return result;
	}
	void solve(string digits,vector<string> &result,string str,int index){
        if(index == digits.size()) {
            result.push_back(str);
            return;
        }
		string combine = s[digits[index]-'0'];
		for(int i=0;i<combine.size();++i){
			solve(digits,result,str+combine.substr(i,1),index+1);
		}
	}
};