 class Solution {
 public:
	 int search(int A[], int n, int target) {
		 int left = 0,right = n-1;
		 while(left<=right){
			 int mid = (left+right)/2;
			 if(A[mid]==target) return mid;
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
		 return -1;
	 }
 };