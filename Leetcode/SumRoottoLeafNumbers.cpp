/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
		int result = 0;
		getValue(root,0,result);
		return result;
    }
private:
	void getValue(TreeNode *root,int pre,int &result)
	{
		if (root==nullptr)
		{
			return;
		}
		pre = pre*10+root->val;
		if (root->left)
		{
			getValue(root->left,pre,result);
		}
		if (root->right)
		{
			getValue(root->right,pre,result);
		}
		if (root->left==nullptr && root->right==nullptr)
		{
			result += pre;
		}
	}
};