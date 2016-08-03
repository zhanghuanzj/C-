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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root==NULL) return result;
        stack<TreeNode*> record;
        record.push(root);
        while(!record.empty()){
            TreeNode* node = record.top();
            record.pop();
            result.push_back(node->val);
            if(node->right){
                record.push(node->right);
            }
            if(node->left){
                record.push(node->left);
            }
        }
        return result;
    }
};