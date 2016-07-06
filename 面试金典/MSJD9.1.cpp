class GoUpstairs {
public:
    int countWays(int n) {
        const unsigned int m = 1000000007;
        unsigned int a[3] = {1,2,4};
        unsigned int result = 0;
        if (n<=0)
        {
        	return 0;
        }
        if (n<=3)
        {
        	return a[n-1];
        }
        else 
        {
        	for (int i = 4; i <= n; ++i)
        	{
        		result = ((a[0] + a[1])%m +a[2])%m;
        		a[0] = a[1];
        		a[1] = a[2];
        		a[2] = result;
        	}
        }
        return result;
    }
};