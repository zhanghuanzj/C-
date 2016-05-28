class Solution {
public:
    double Power(double base, int exponent) {
    	double result = 1;
    	bool flag = false;
    	if (exponent<0)
    	{
    		flag = true;
    		exponent = -exponent;
    	}
    	while(exponent)
    	{
    		if (exponent&1)
    		{
    			result *= base;
    		}
    		base *= base;
    		exponent = exponent>>1;
    	}
    	if (flag)
    	{
    		result = 1/result;
    	}
    	return result;
    }
};