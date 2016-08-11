class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return solve(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1);
    }
    TreeNode *solve(vector<int> &inorder,int il,int ir,vector<int> &preorder,int pl,int pr){
        if(il>ir) return nullptr;
        int v = preorder[pl];
        int index = il;
        while(inorder[index]!=v)
            ++index;
        int offset = index-il;
        TreeNode *node = new TreeNode(v);
        node->left = solve(inorder,il,index-1,preorder,pl+1,pl+offset);
        node->right = solve(inorder,index+1,ir,preorder,pl+offset+1,pr);
        return node;
    }
};