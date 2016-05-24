class Solution {
public:
	void replaceSpace(char *str,int length) {
		if (str==NULL||length<=0)
		{
			return;
		}
		int count = 0;
		int original = 0;
		for (int i = 0; i < length; ++i)
		{
			if (str[i]=='\0')
			{
				break;
			}
			if (str[i]==' ')
			{
				++count;
			}
			++original;
		}
		if (count)
		{
			int index = original+2*count;
			while(original>=0)
			{
				if (str[original]!=' ')
				{
					str[index--] = str[original];
				}
				else
				{
					str[index--] = '0';
					str[index--] = '2';
					str[index--] = '%';
				}
				--original;
			}
		}
	}
};