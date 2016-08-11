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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        solve(root,sum,path,result);
        return result;
    }
    void solve(TreeNode *root,int sum,vector<int> &path,vector<vector<int>> &result){
        if(root==NULL) return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val==sum){ 
            result.push_back(path);
        }else{
            solve(root->left,sum-root->val,path,result);
            solve(root->right,sum-root->val,path,result);
        }
        path.pop_back();
    }
};