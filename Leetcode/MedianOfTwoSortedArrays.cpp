class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size = nums1.size()+nums2.size(); 
		if (size%2==1){
			return findKth(nums1,nums2,0,0,size/2+1);
		}else{
			return ((double)findKth(nums1,nums2,0,0,size/2)+findKth(nums1,nums2,0,0,size/2+1))/2;
		}
	}
	int findKth(vector<int>& v1,vector<int>& v2,int s1,int s2,int k)
	{
		int m = v1.size()-s1;
		int n = v2.size()-s2;
		if (m>n){
			return findKth(v2,v1,s2,s1,k);
		}
		if (m==0){
			return v2[s2+k-1];
		}
		if (k==1){
			return min(v1[s1],v2[s2]);
		}
		int s1_num = min(k/2,m);
		int s2_num = k-s1_num;
		if (v1[s1+s1_num-1] > v2[s2+s2_num-1]){
			return findKth(v1,v2,s1,s2+s2_num,k-s2_num);
		}else if (v1[s1+s1_num-1] < v2[s2+s2_num-1]){
			return findKth(v1,v2,s1+s1_num,s2,k-s1_num);
		}else{
			return v1[s1+s1_num-1];
		}
	}
};