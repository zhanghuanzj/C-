class Solution {
public:
	void recoverTree(TreeNode *root) {
		if(root==nullptr) return;
		vector<TreeNode*> record;
		TreeNode* pre = nullptr;
		solve(pre,root,record);
		if(!record.empty()){
			swap(record[0]->val,record[1]->val);
		}else{
			if(root->left) swap(root->left->val,root->val);
			else swap(root->right->val,root->val);
		}
	}
	void solve(TreeNode *&pre,TreeNode *root,vector<TreeNode*> &record){
		if(root==nullptr) return;
		solve(pre,root->left,record);
		check(pre,root,record);
		pre = root;
		solve(pre,root->right,record);
	}
	void check(TreeNode *pre,TreeNode *root,vector<TreeNode*> &record){
		if(pre==nullptr) return;
		if(pre->val>root->val){
			if(record.empty()){
				record.push_back(pre);
				record.push_back(root);
			}else{
				record[1] = root;
			}
		}
	}
};