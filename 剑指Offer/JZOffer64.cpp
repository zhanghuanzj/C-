class Solution {
public:
	void Insert(int num)
	{
		int size = minHeap.size()+maxHeap.size();
		if ((size&1)==0)  //偶数
		{
			if (!maxHeap.empty()&&num>maxHeap.top())
			{
				minHeap.push(num);
				num = minHeap.top();
				minHeap.pop();
			}
			maxHeap.push(num);
		}
		else
		{
			if (num<maxHeap.top())
			{
				maxHeap.push(num);
				num = maxHeap.top();
				maxHeap.pop();
			}
			minHeap.push(num);
		}
	}

	double GetMedian()
	{ 
		int size = minHeap.size()+maxHeap.size();
		if (size&1)
		{
			return maxHeap.top();
		}
		return (double(maxHeap.top()+minHeap.top()))/2;
	}
private:
	priority_queue<int,vector<int>,greater<int>> minHeap;
	priority_queue<int> maxHeap;
};