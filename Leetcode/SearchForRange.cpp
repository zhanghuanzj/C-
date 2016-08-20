class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> result(2,0);
		result[0] = searchFirst(A,n,target);
		result[1] = searchLast(A,n,target);
		return result;
	}
	int searchFirst(int A[],int n,int target){
		int left = 0,right = n-1;
		while(left<right){
			int mid = (left+right)/2;
			if(A[mid]==target) right = mid;
			else if(A[mid]>target) right = mid-1;
			else left = mid+1;
		}
        if(n<=0 || A[left]!=target) return -1;
        return left;
	}
	int searchLast(int A[],int n,int target){
		int left = 0,right = n-1;
		while(left<right){
			int mid = (left+right+1)/2;       //防止[2,2]死循环
			if(A[mid]==target) left = mid;
			else if(A[mid]>target) right = mid-1;
			else left = mid+1;
		}
		if(n<=0 || A[left]!=target) return -1;
        return left;
	}
};