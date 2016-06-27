/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Checker {
public:
	bool checkBST(TreeNode* root) {
		return solve(root,INT_MIN,INT_MAX);
	}
	bool solve(TreeNode* root,int mi,int mx)
	{
		if (root==NULL)
		{
			return true;
		}
		if (root->val<=mi||root->val>=mx)
		{
			return false;
		}
		if (solve(root->left,mi,root->val)&&solve(root->right,root->val,mx))
		{
			return true;
		}
		return false;
	}
};