class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size()==0)
		{
			return 0;
		}
		int n = prices.size();
		vector<int> left(n,0);
		vector<int> right(n,0);
		int lv = 0,rv = 0,mini = prices.front(),maxi = prices.back();
		for (int i=1;i<n;++i)
		{
			left[i] = max(lv,prices[i]-mini);
			mini = min(mini,prices[i]);
			lv = left[i];

			right[n-i-1] = max(rv,maxi-prices[n-i-1]);
			maxi = max(maxi,prices[n-i-1]);
			rv = right[n-i-1];
		}
		int result = 0;
		for (int i=0;i<n;++i)
		{
			result = max(result,left[i]+right[i]);
		}
		return result;
	}
};