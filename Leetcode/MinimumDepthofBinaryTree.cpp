class Solution {
public:
    int run(TreeNode *root) {
        if(root == nullptr) return 0;
        int left = run(root->left);
        int right = run(root->right);
        if(left==0 || right==0)
            return left==0?(right+1):(left+1);
        return min(left,right)+1;
    }
};