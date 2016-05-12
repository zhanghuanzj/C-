class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (str.size())
		{
			int k = n%str.size();
			if (k)
			{
				reverse(str,0,k-1);
				reverse(str,k,str.size()-1);
				reverse(str,0,str.size()-1);
			}
		}
		return str;
	}

	void reverse(string &s,int left,int right)
	{
		while (left<right)
		{
			swap(s[left++],s[right--]);
		}
	}
};