class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int target;
    	int count = 0;
    	for(auto v:numbers)
    	{
    		if (count==0)
    		{
    			target = v;
    			count = 1;
    		}
    		else if (target == v)
    		{
    			++count;
    		}
    		else
    		{
    			--count;
    		}
    	}
    	count = 0;
    	for(auto v:numbers)
    	{
    		if (target == v)
    		{
    			++count;
    		}
    	}
    	return (count>0&&(count>numbers.size()/2))?target:0;
    }
};