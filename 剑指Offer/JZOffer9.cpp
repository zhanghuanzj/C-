class Solution {
public:
    int Fibonacci(int n) {
    	if (n==0||n==1)
    	{
    		return n;
    	}
    	int f1 = 0, f2 =1;
    	int result;
    	for (int i = 2; i <= n; ++i)
    	{
    		result = f1+f2;
    		f1 = f2;
    		f2 = result;
    	}
    	return result;
    }
};