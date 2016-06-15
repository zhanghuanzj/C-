class Different {
public:
    bool checkDifferent(string iniString) {
        sort(iniString.begin(), iniString.end());
        for (int i = 0; i < iniString.size()-1; ++i)
        {
        	if (iniString[i]==iniString[i+1])
        	{
        		return false;
        	}
        }
        return true;
    }
};