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
    bool isBalanced(TreeNode *root) {
        int depth;
        return solve(root,depth);
    }
    bool solve(TreeNode *root,int &depth){
        if(root==NULL){
            depth = 0;
            return true;
        }else{
            int ld = 0,rd = 0;
            if(!(solve(root->left,ld)&&solve(root->right,rd))){
                return false;
            }else{
                if(abs(ld-rd)>1) return false;
                depth = max(ld,rd)+1;
            }
        }
        return true;
    }
};