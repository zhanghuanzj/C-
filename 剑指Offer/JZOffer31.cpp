class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
    	int result = INT_MIN;
    	int sum = 0;
    	for(auto v:array)
    	{
    		sum += v;
            result = max(result,sum);
    		if (sum<0)
    		{
    			sum = 0;
    		}
    	}
    	return result;
    }
};