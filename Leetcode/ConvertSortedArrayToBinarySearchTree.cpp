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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return solve(num,0,num.size()-1);
    }
    TreeNode *solve(vector<int> &num,int left,int right){
        if(left>right) return nullptr;
        int mid = (left+right+1)/2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = solve(num,left,mid-1);
        node->right = solve(num,mid+1,right);
        return node;
    }
};