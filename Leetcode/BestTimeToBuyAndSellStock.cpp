class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int mini = prices.front();
        int result = 0;
        for(int i=1;i<prices.size();++i){
            result = max(result,prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return result;
    }
};