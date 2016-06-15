class Same {
public:
    bool checkSam(string stringA, string stringB) {
        vector<int> record(256);
        for(auto s:stringA)
        {
        	record[s]++;
        }
        for(auto s:stringB)
        {
        	record[s]--;
        }
        for(auto n:record)
        {
        	if (n!=0)
        	{
        		return false;
        	}
        }
        return true;
    }
};