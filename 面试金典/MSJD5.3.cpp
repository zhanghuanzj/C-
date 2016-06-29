class CloseNumber {
public:
	int getMax(int n)
	{
		int one = 0;
		int index = 0;
		int x = n;
		while((x&1)||!one)  //如果是1||是0但还没出现过1
		{
			if (x&1)
			{
				++one;
			}
			++index;
			x = x>>1;
		}
		n |= (1<<index);       //置1
		n &= ~((1<<index)-1);  //右边清0
		n |= (1<<(one-1))-1;   //右边补1
		return n;
	}
	int getMin(int n)
	{
		int zero = 0;
		int index = 0;
		int x = n;
		while(!(x&1)||!zero)  //如果是0||是1但还没出现过0
		{
			if (!(x&1))
			{
				++zero;
			}
			++index;
			x = x>>1;
		}
		n &= ~((1<<(index+1))-1);  //右边清0
		n |= ((1<<(index-zero+1))-1)<<(zero-1);   //右边补1
		return n;
	}
	vector<int> getCloseNumber(int x) {
		vector<int> result;
		result.push_back(getMin(x));
		result.push_back(getMax(x));
		return result;
	}
};