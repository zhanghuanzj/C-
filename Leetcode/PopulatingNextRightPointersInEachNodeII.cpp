/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root==nullptr)
		{
			return;
		}
		queue<TreeLinkNode*> record;
		record.push(root);
		int remain = 1;
		int newRemain = 0;
		while (!record.empty())
		{
			TreeLinkNode *node = record.front();
			record.pop();
			--remain;
			if (node->left)
			{
				record.push(node->left);
				newRemain++;
			}
			if (node->right)
			{
				record.push(node->right);
				newRemain++;
			}
			if (remain==0)
			{
				node->next = nullptr;
				remain = newRemain;
				newRemain = 0;
			}
			else
			{
				node->next = record.front();
			}
		}
		return;
	}
};