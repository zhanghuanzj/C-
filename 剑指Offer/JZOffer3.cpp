class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        if (array.empty()||array[0].empty())
        {
        	return false;
        }
        int m = array.size(),n = array[0].size();
       	for(int l = 0;l<m;++l)
		{
            if (array[l][0]<=target)
            {
                int left = 0,right = n-1;
                while(left<=right)
                {
                    int mid = (left+right)/2;
                    if (array[l][mid]==target)
                    {
                        return true;
                    }
                    else if (array[l][mid]<target)
                    {
                        left = mid+1;
                    }
                    else
                    {
                        right = mid-1;
                    }
                }
            }
        }
        
        return false;
    }
};