class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> result;
		if (num.size()>=size&&size>0)
		{
			deque<int> index;
			for (int i=0;i<size;++i)
			{
				while (!index.empty()&&num[index.back()]<num[i])      //更新队列
				{
					index.pop_back();
				}
				index.push_back(i);
			}
			result.push_back(num[index.front()]);
			for (int i=size;i<num.size();++i)
			{
				while (!index.empty()&&num[index.back()]<num[i])
				{
					index.pop_back();
				}
				if (!index.empty()&&index.front()<=(i-size))        //最前的值已经滑出滑动窗口
				{
					index.pop_front();
				}
				index.push_back(i);
				result.push_back(num[index.front()]);
			}
		}
		return result;
	}
};