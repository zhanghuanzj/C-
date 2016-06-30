class Finder {
public:
    int findMissing(vector<vector<int> > numbers, int n) {
        for (int i = 0; i < n; ++i)
        {
        	if ((i&1)!=numbers[i][0])
        	{
        		return i;
        	}
        }
        return n;
    }
};