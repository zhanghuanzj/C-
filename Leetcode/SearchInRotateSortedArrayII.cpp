 class Solution {
 public:
	 bool search(int A[], int n, int target) {
		 int left = 0,right = n-1;
		 while(left<=right){
			 while(left<right&&A[left]==A[left+1]) ++left;
			 while(left<right&&A[right]==A[right-1]) --right;
			 int mid = (left+right)/2;
			 if(A[mid]==target) return true;
			 if(A[mid]<A[right])     //右有序
			 {
				 if(A[mid]<target&&target<=A[right]) left = mid+1;
				 else right = mid-1;
			 }
			 else                    //左有序
			 {
				 if(A[mid]>target&&target>=A[left]) right = mid-1;
				 else left = mid+1;
			 }
		 }
		 return false;
	 }
 };