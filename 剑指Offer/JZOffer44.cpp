class Solution {
public:
	bool IsContinuous( vector<int> numbers ) {
		if(numbers.size()<5) return false;
		int max = INT_MIN,min = INT_MAX;
		int zeroCount = 0;
		for(auto v : numbers)
		{
			if(v!=0)
			{
				if(v>max) max = v;
				if(v<min) min = v;
			}
			else
			{
				++zeroCount;
			}
		}
		if(max-min>4) return false;
		if(zeroCount==4) return true;
		vector<int> vec(5);
		for(auto v : numbers)
		{
			if(v!=0)
			{
				++vec[v-min];
			}
		}
		for(auto v : vec) 
			if(v>1) return false;

		return true;
	}
};