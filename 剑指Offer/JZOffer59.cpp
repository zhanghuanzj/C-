
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
    bool isSymmetrical(TreeNode* pRoot)
    {
    	if (pRoot==NULL)
    	{
    		return true;
    	}
    	return isSame(pRoot->left,pRoot->right);
    }
    bool isSame(TreeNode* pRoot1,TreeNode* pRoot2)
    {
    	if (pRoot2==NULL&&pRoot1==NULL)
    	{
    		return true;
    	}
    	if (pRoot1==NULL||pRoot2==NULL)
    	{
    		return false;
    	}
    	if (pRoot1->val!=pRoot2->val)
    	{
    		return false;
    	}
    	return isSame(pRoot1->left,pRoot2->right)&&isSame(pRoot1->right,pRoot2->left);
    }
};