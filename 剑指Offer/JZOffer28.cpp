class Solution {
public:
    vector<string> Permutation(string str) {
    	set<string> results;
        vector<string> result;
        if (!str.empty())
    	{
    		solve(str,0,results);
    		for(auto s:results)
    		{
    			result.push_back(s);
    		}
    	}
    	return result;
    }
    void solve(string &str,int index,set<string> &results)
    {   	
    	if (str.size()==index)
    	{
    		results.insert(str);
    	}
    	else
    	{
    		for (int i = index; i < str.size(); ++i)
    		{
    			swap(str[i],str[index]);
    			solve(str,index+1,results);
    			swap(str[i],str[index]);
    		}
    	}
    }
};