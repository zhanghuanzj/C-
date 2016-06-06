class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
    	if (sequence.empty())
    	{
    		return false;
    	}
    	return solve(sequence,0,sequence.size()-1)
    }

    bool solve(vector<int> sequence,int b,int e)
    {
    	if (b<=e)
    	{
    		return true;
    	}
    	int index = e;
    	for (int i = 0; i < e; ++i)
    	{
    		if (sequence[i]>sequence[e])
    		{
    			index = i;
    			break;
    		}
    	}
    	bool flag = true;
    	for (int i = index; i < e; ++i)
    	{
    		if (sequence[i]<sequence[e])
    		{
    			return false;
    		}
    	}
    	return solve(sequence,b,index-1)&&solve(sequence,index,e);
    }
};