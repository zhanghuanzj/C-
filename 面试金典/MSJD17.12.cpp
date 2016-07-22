class FindPair {
public:
	int countPairs(vector<int> A, int n, int sum) {
		sort(A.begin(),A.end());
		int left = 0,right = n-1;
		int count = 0;
		while(left<right){
			int temp = A[left]+A[right];
			if(temp==sum){
				if(A[left]==A[right]){
					count += (right-left+1)*(right-left)/2;
					break;
				}
				else{
					int x = 1,y = 1;
					++left;
					while(A[left]==A[left-1]){
						++x;
						++left;
					}
					--right;
					while(A[right]==A[right+1]){
						++y;
						--right;
					}
					count += x*y;
				}
			}
			else if(temp>sum) 
			{
				--right;
			}
			else
				++left;
		}
		return count;
	}
};