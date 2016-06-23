/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Balance {
public:
    bool isBalance(TreeNode* root) {
        int h = 0;
        return solve(root,h);
    }

    bool solve(TreeNode *node,int &h)
    {
    	if (node==NULL)
    	{
    		return true;
    	}
    	else
    	{
    		int left=0,right=0;
    		if (solve(node->left,left)&&solve(node->right,right))
    		{
    			if (abs(left-right)>1)
    			{
    				return false;
    			}
    			h = max(left,right)+1;
    			return true;
    		}
    		return false;
    	}
    }
};