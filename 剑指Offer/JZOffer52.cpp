class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int> result(A.size());
    	vector<int> temp(A.size());
    	if (A.size()>0)
    	{
    		temp[0] = 1;
    		for(int i=1;i<A.size();++i)
    		{
    			temp[i] = A[i-1]*temp[i-1];
    		}
    		int sum = 1;
    		for (int i = A.size()-1; i >=0; --i)
    		{
    			result[i] = temp[i]*sum;
    			sum *= A[i];
    		}
    	}
    	return result;
    }
};