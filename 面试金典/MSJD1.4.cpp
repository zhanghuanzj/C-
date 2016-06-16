class Replacement {
public:
	string replaceSpace(string iniString, int length) {
		int en = 0;
		for(auto c:iniString)
		{
			if (c==' ')
			{
				en++;
			}
		}
		int newLength = length + en*2-1;
		string s(newLength+1,' ');
		for (int i = length-1; i >= 0 ; --i)
		{
			if (iniString[i]==' ')
			{
				s[newLength--] = '0';
				s[newLength--] = '2';
				s[newLength--] = '%';
			}
			else
			{
				s[newLength--] = iniString[i];
			}
		}
		return s;
	}
};