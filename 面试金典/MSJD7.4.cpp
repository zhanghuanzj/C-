class AddSubstitution {
public:
	int nega(int v)
	{
		int result = 0;
		int d = v>0?-1:1;
		int count = abs(v);
		while(count--)
		{
			result += d;
		}
		return result;
	}
	int minus(int a,int b)
	{
		return a + nega(b);
	}
	int multi(int a,int b)
	{
		if (abs(a)<abs(b))	
		{
			return multi(b,a);
		}
		else
		{
			int result = 0;
			int count = abs(b);
			while(count--)
			{
				result += a;
			}
			return b>0?result:nega(result);
		}
	}
	int divide(int a,int b)
	{
		int absa = abs(a);
		int absb = abs(b);
		int sum = 0,result = 0;
		while(sum+absb<=absa)
		{
			sum += absb;
			++result;
		}
		if ((a>0&&b>0)||(a<0&&b<0))
		{
			return result;
		}
		return nega(result);
	}
    int calc(int a, int b, int type) {
        if (type==1)
        {
        	return multi(a,b);
        }
        else if (type==0)
        {
        	return divide(a,b);
        }
        else if (type==-1)
        {
        	return minus(a,b);
        }
        return 0;
    }
};