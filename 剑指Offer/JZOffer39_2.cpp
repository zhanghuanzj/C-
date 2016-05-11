class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
		return isBalanced(pRoot,depth);
	}

	bool isBalanced(TreeNode* pRoot,int &dep)
	{
		if (pRoot==nullptr)
		{
			dep = 0;
			return true;
		}
		int ld=0,rd=0;
		if (isBalanced(pRoot->left,ld)&&isBalanced(pRoot->right,rd))
		{
			dep = max(ld,rd)+1;
			return abs(ld-rd)<=1;
		}
		return false;
	}
};