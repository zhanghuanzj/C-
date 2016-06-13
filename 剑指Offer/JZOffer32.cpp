class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	if (n<1)
    	{
    		return 0;
    	}
    	int factor = 1;
    	int count = 0;
    	while(n/factor)
    	{
    		int lowNumber = n%factor;
    		int highNumber = n/(factor*10);
    		int curNumber = (n/factor)%10;
    		switch(curNumber)
    		{
    			case 0:
    				count += highNumber*factor;
    				break;
    			case 1:
    				count += highNumber*factor + lowNumber+1;
    				break;
    			default:
    				count += (highNumber+1)*factor;
    				break;
    		}
            factor *= 10;
    	}
    	return count;
    }
};