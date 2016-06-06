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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int>> result;
		vector<int> path;
		solve(root,result,path,0,expectNumber);
		return result;
    }

    void solve(TreeNode* root,vector<vector<int>> &result,vector<int> path,int sum,int target)
    {
    	if (root==NULL)
    	{
    		return ;
    	}
    	path.push_back(root->val);
    	sum += root->val;
    	if (sum==target&&root->left==NULL&&root->right==NULL)
    	{
    		result.push_back(path);
    	}
    	solve(root->left,result,path,sum,target);
    	solve(root->right,result,path,sum,target);
    	path.pop_back();
    }
};