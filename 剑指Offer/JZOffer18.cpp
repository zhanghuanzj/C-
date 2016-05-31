/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
    	if (pRoot1==NULL||pRoot2==NULL)
    	{
    		return false;
    	}
    	else if (pRoot2!=NULL&&pRoot1!=NULL)
    	{
    		if (pRoot1->val==pRoot2->val&&isSame(pRoot1,pRoot2))
    		{
    			return true;
    		}
    		else
    		{
    			return HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
    		}
    	}
    	return false;
    }

    bool isSame(TreeNode *r1,TreeNode *r2)
    {
    	if (r2==NULL)	
    	{
    		return true;
    	}
    	else if (r1!=NULL&&r2!=NULL)
    	{
    		if (r1->val==r2->val)
    		{
    			return isSame(r1->left,r2->left)&&isSame(r1->right,r2->right);
    		}
    		return false;
    	}
    	return false;
    }
};