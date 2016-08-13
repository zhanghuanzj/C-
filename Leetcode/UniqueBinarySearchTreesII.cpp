class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return solve(1,n);
    }
    vector<TreeNode*> solve(int left,int right){
        vector<TreeNode*> result;
        if(left>right){
            result.push_back(nullptr);
        }else if(left==right) {
            result.push_back(new TreeNode(left));
        }else {
            for(int i=left;i<=right;++i){
            	vector<TreeNode*> leftTree = solve(left,i-1);
                vector<TreeNode*> rightTree = solve(i+1,right);
                for(int x=0;x<leftTree.size();++x){
                    for(int y=0;y<rightTree.size();++y){
                        TreeNode *node = new TreeNode(i);
                        node->left = leftTree[x];
                        node->right = rightTree[y];
                        result.push_back(node);
                    }
                }
       		}
        }
        return result;
    }   
};