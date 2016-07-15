class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		int left = 0;
		int right = n-1;
		while(left<right)
		{
			if (A[left]<A[right])
			{
				int mid = (left+right)/2;
				if (A[mid]>x)
				{
					right = mid-1;
				}
				else if (A[mid]==x)
				{
					return mid;
				}
				else
				{
					left = mid+1;
				}
			}
			else
			{
				if (x>=A[left])
				{
					int mid = (left+right)/2;
					if (A[mid]>x)
					{
						right = mid-1;
					}
					else if (A[mid]==x)
					{
						return mid;
					}
					else
					{
						if (A[mid]>=A[left])
						{
							left = mid+1;
						}
						else
						{
							right = mid-1;
						}
					}
				}
				else
				{
					int mid = (left+right)/2;
					if (A[mid]<x)
					{
						left = mid+1;
					}
					else if (A[mid]==x)
					{
						return mid;
					}
					else
					{
						if (A[mid]<=A[right])
						{
							right = mid-1;
						}
						else
						{
							left = mid+1;
						}
					}
				}
			}
		}
		return left;
	}
};