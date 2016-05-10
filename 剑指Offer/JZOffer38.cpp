class Solution {
public:
	int GetNumberOfK(vector<int> data ,int k) {
		if (data.empty())
		{
			return 0;
		}
		int first = getFirst(data,k);
		int second = getLast(data,k);
		if (first!=-1)
		{
			return second-first+1;
		}
		return 0;
	}
	int getFirst(vector<int> &data,int v)
	{
		int left=0,right=data.size()-1;
		while (left<right)
		{
			int mid = left+(right-left)/2;
			if (data[mid]==v)
			{
				right = mid;
			}
			else if (data[mid]>v)
			{
				right = mid-1;
			}
			else
			{
				left = mid+1;
			}
		}
		if (data[left]==v)
		{
			return left;
		}
		return -1;
	}
	int getLast(vector<int> &data,int v)
	{
		int left=0,right=data.size()-1;
		while (left<right)
		{
			int mid = left+(right-left+1)/2;
			if (data[mid]==v)
			{
				left = mid;
			}
			else if (data[mid]>v)
			{
				right = mid-1;
			}
			else
			{
				left = mid+1;
			}
		}
		if (data[left]==v)
		{
			return left;
		}
		return -1;
	}
};




class Solution {
public:
	int GetNumberOfK(vector<int> data ,int k) {
		if (data.empty())
		{
			return 0;
		}
		auto first = lower_bound(data.begin(),data.end(),k);
		auto second = upper_bound(data.begin(),data.end(),k);
		if (first!=data.end())
		{
			return second-first;
		}
		return 0;
	}
};