class Solution {
public:
	int jump(vector<int>& nums) {         //区间步进
		int n = nums.size();
		int step = 0,maxIndex = 0,nextIndex = 0;
		for (int i=0;i<n-1;++i) {
			if (i>maxIndex){
				maxIndex = nextIndex;
				++step;
			}
			nextIndex = max(nextIndex,nums[i]+i);
			if(nextIndex>=n-1) return step+1;
		}
		return step;
	}
};