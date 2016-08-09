class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n<2)
        {
            return 0;
        }
        if (k>n/2)
        {
            int result = 0;
            for (int i=1;i<n;++i)
            {
                if (prices[i]>prices[i-1])
                {
                    result += prices[i]-prices[i-1];
                }
            }
            return result;
        }
        vector<int> buy(k+1,INT_MIN);
        vector<int> sell(k+1,0);
        for (int i=0;i<n;++i)
        {
            for (int j=k;j>0;--j)
            {
                sell[j] = max(sell[j],buy[j]+prices[i]);
                buy[j] = max(buy[j],sell[j-1]-prices[i]);
            }
        }
        return sell[k];
    }
};