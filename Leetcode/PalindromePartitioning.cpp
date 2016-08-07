class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> palindrome;
		getPalindrome(s,palindrome,result);
		return result;
	}
private:
	void getPalindrome(string s,vector<string> &palindrome,vector<vector<string>> &result)
	{
		if (s.size()==0)
		{
			result.push_back(palindrome);
			return;
		}
		for (int i=0;i<s.size();++i)
		{
			int begin = 0;
			int end = i;
			while (s[begin]==s[end]&&begin<end)
			{
				++begin,--end;
			}
			if (begin>=end)
			{
				palindrome.push_back(s.substr(0,i+1));
				getPalindrome(s.substr(i+1),palindrome,result);
				palindrome.pop_back();
			}
		}
	}
};