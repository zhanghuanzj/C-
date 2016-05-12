class Solution {
public:
	string ReverseSentence(string str) {
		int left = 0,right = 0;
		while (right<str.size())
		{
			if (right==str.size()-1)
			{
				reverse(str,left,right++);
			}
			else if (str[right]==' ')
			{
				reverse(str,left,--right);
				right += 2;
				left = right;
			}
			else
			{
				++right;
			}
		}
		reverse(str,0,str.size()-1);
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