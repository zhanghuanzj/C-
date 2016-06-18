class Zipper {
public:
    string zipString(string iniString) {
        string new_string;
        int index = 0;
        stringstream ss;
        while(index<iniString.size())
        {
        	char c = iniString[index];
        	int count = 1;
        	++index;
        	while(index<iniString.size()&&iniString[index]==c)
        	{
        		++count;
        		++index;
        	}
        	ss<<c<<count;
        }
        if (index>0)
        {
        	ss>>new_string;
        }
        if (new_string.size()>=iniString.size())
        {
        	return iniString;
        }
        return new_string;
    }
};