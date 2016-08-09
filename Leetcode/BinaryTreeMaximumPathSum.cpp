class Solution {
public:
	int maxPathSum(TreeNode *root) {
		int maxsum = INT_MIN;
		getPathSum(root,maxsum);
		return maxsum;
	}
	int getPathSum(TreeNode *root,int &maxSum)
	{
		if (root==nullptr)
		{
			return 0;
		}
		int left = max(0,getPathSum(root->left,maxSum));    //若和为负则不算入
		int right = max(0,getPathSum(root->right,maxSum));
		maxSum = max(maxSum,left+right+root->val);
		return max(left,right)+root->val;
	}
};