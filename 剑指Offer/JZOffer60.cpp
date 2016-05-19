
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> result;
		if (pRoot==NULL)
		{
			return result;
		}
		int current = 1;
		int next = 0;
		queue<TreeNode*> q;
		q.push(pRoot);
		while(!q.empty())
		{
			vector<int> v;
			while(current--)
			{
				TreeNode* p = q.front();
				q.pop();
				v.push_back(p->val);
				if (p->left!=NULL)
				{
					q.push(p->left);
					next++;
				}
				if (p->right!=NULL)
				{
					q.push(p->right);
					next++;
				}
			}
			result.push_back(v);
			current = next;
			next = 0;
		}
		return result;
	}
};