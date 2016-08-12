class Solution {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode* pre = nullptr;
        return solve(pre,root);
    }
    bool solve(TreeNode *&pre,TreeNode *root){
        if(root==nullptr) return true;
        bool result = solve(pre,root->left);
        if(pre!=nullptr && pre->val >= root->val) 
            return false;
        pre = root;
        return result && solve(pre,root->right);  
    }
};