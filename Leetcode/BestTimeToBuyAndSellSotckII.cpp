class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int result = 0;
		for(auto i=1;i<prices.size();++i){
			if(prices[i]>prices[i-1]){
				result += prices[i]-prices[i-1];
			}
		}
		return result;
	}
};