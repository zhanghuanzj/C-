class Solution {
public:
	int InversePairs(vector<int> data) {
		vector<int> temp(data.size());
		return fun(data,temp,0,data.size()-1);
	}

	int fun(vector<int> &data,vector<int> &temp,int l,int r)
	{
		if (l>r)
		{
			return 0;
		}
		if (l==r)
		{
			temp[l] = data[l];
			return 0;
		}
		else
		{
			int mid = (l+r)/2;
			int count = 0;
			count += fun(data,temp,l,mid);
			count += fun(data,temp,mid+1,r);
			int rIndex = r;
			int lIndex = mid;
			int index = r;

			while (lIndex>=l&&rIndex>mid)
			{
				if(data[lIndex]>data[rIndex])
				{
					temp[index--] = data[lIndex--];
					count += rIndex-mid;
				}
				else
				{
					temp[index--] = data[rIndex--];
				}
			}
			while (lIndex>=l)
			{
				temp[index--] = data[lIndex--];
			}
			while (rIndex>mid)
			{
				temp[index--] = data[rIndex--];
			}
			for (int i=l;i<=r;++i)
			{
				data[i] = temp[i];
			}
			return count;
		}
	}
};