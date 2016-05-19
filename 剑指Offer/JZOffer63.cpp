
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
    	unsigned int n = 0;
        return solve(pRoot,k,n);
    }
    TreeNode* solve(TreeNode* node,unsigned int k,unsigned int &n)
    {
    	if (node==NULL)
    	{
    		return NULL;
    	}
    	TreeNode *left = solve(node->left,k,n);
    	if (left!=NULL)
    	{
    		return left;
    	}
        if(node!=NULL) ++n;
    	if (n==k)
    	{
    		return node;
    	}
    	TreeNode *right = solve(node->right,k,n);
    	return right;
    }
    
};