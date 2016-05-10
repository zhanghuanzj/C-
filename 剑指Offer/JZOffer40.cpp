class Solution {
public:
	void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		if (data.size()<2)
		{
			return;
		}
		int exclusive = 0;
		for(auto v : data)
		{
			exclusive^=v;
		}
		exclusive &= (-exclusive);
		*num1=*num2=0;
		for (auto v : data)
		{
			if (v&exclusive)
			{
				*num1^=v;
			}
			else
			{
				*num2^=v;
			}
		}
	}
};