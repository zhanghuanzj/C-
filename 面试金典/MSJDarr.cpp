class AntiOrder {
public:
	int count(vector<int> A, int n) {
		return mergesort(A,0,n-1);
	}
	int mergesort(vector<int> &a,int left,int right){
		if(left>=right) return 0;
		int mid = (left+right)/2;
		return mergesort(a,left,mid)+mergesort(a,mid+1,right)+merge(a,left,mid,mid+1,right);
	}

	int merge(vector<int> &a,int l1,int r1,int l2,int r2){
		if(l1>r1||l2>r2) return 0;
		int count = 0,index = 0;
		int left = l1,right = r2;
		vector<int> v(right-left+1);
		while(l1<=r1&&l2<=r2){
			if(a[l1]<=a[l2]){
				v[index++] = a[l1++];
			}
			else{
				v[index++] = a[l2++];
				count +=r1-l1+1;
			}
		}
		while(l1<=r1){
			v[index++] = a[l1++];
		}
		while(l2<=r2){
			v[index++] = a[l2++];
		}
		for(int i=left;i<=right;++i){
			a[i] = v[i-left];
		}
		return count;
	}
};