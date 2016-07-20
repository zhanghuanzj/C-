class Rearrange {
public:
	vector<int> findSegment(vector<int> A, int n) {
		vector<int> result(2);
		int left = 0,right = n-1;
		while (left<n-1 && A[left]<=A[left+1])
			++left;
		while (right>0 && A[right]>=A[right-1])
			--right;
		if (left<right)
		{
			int minimum = A[left+1];
			for (int i=left+2;i<=right;++i)
			{
				if (A[i]<minimum)
				{
					minimum = A[i];
				}
			}
			int maximum = A[left];
			for (int i=left+1;i<right;++i)
			{
				if (A[i]>maximum)
				{
					maximum = A[i];
				}
			}
			while (left>0 && A[left-1]>minimum)
				--left;
			while (right<n-1 && A[right+1]<maximum)
				++right;
			result[0] = left;
			result[1] = right;
		}
		return result;
	}
};