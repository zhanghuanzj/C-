class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode *solve(vector<int> &inorder,int il,int ir,vector<int> &postorder,int pl,int pr){
        if(il>ir) return nullptr;
        int v = postorder[pr];
        int index = il;
        while(inorder[index]!=v)
            ++index;
        int offset = index-il;
        TreeNode *node = new TreeNode(v);
        node->left = solve(inorder,il,index-1,postorder,pl,pl+offset-1);
        node->right = solve(inorder,index+1,ir,postorder,pl+offset,pr-1);
        return node;
    }
};