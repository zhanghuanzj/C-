class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> result;
		int threshold = (sum+1)/2;
		int left = 1;
		int right = 2;
		while (left<threshold)
		{
			int temp = (left+right)*(right-left+1)/2;
			if (temp==sum)
			{
				vector<int> v;
				for (int i=left;i<=right;++i)
				{
					v.push_back(i);
				}
                ++right;
				result.push_back(v);
			}
			else if(temp>sum)
			{
				 ++left;
			}
			else
			{
				++right;
			}
		}
		return result;
	}
};