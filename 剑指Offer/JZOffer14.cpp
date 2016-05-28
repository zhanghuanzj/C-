class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int pre = 0, post = 0;
        while(pre<array.size()&&post<array.size())
        {
        	while( pre<array.size() && (array[pre]&1) )
        	{
        		++pre;
        	}
            post = pre;
        	while( post<array.size() && !(array[post]&1) )
        	{
        		++post;
        	}
        	if (pre<array.size()&&post<array.size())
        	{
                int temp = array[post];
        		for(int i=post;i>pre;--i)
                    array[i] = array[i-1];
                array[pre] = temp;
        	}
        }
    }
};