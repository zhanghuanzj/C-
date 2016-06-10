class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k<=0||input.size()<k)
		{
			return vector<int>();
		}
		else
		{
			int count = 0;
			int b = 0, e = input.size()-1;
			while(true)
			{
				int index = solve(input,b,e);
				int temp = index-b+1+count;
				if (temp==k)
				{
					break;
				}
				else if (temp<k)
				{
					b = index+1;
					count = temp;
				}
				else
				{
					e = index-1;
				}
			}
		}
		vector<int> result;
		for(int i=0;i<k;++i)
			result.push_back(input[i]);

		return result;
	}
	int solve(vector<int> &v,int b,int e)
	{
		int val = v[b];
		int i=b;
		for(int j=i+1;j<=e;++j)
		{
			if (v[j]<val)
			{
				swap(v[++i],v[j]);
			}
		}
		swap(v[b],v[i]);
		return i;
	}
};