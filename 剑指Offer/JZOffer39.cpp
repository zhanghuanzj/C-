class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot==nullptr)
		{
			return 0;
		}
		return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
	}
};