/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Successor {
public:
	bool isFind ;
	int findSucc(TreeNode* root, int p) {
		int result = -1;
		isFind = false;
		solve(root,p,result);
		return result;
	}
	void solve(TreeNode *root,int p,int &result)
	{
		if (root==NULL)
		{
			return ;
		}
		solve(root->left,p,result);
		if (isFind)
		{
			result = root->val;
			isFind = false;
		}
		else if (root->val==p)
		{
			isFind = true;
		}
		solve(root->right,p,result);
	}
};