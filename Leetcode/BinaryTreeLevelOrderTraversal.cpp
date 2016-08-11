class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;
        queue<TreeNode*> record;
        record.push(root);
        int remain = 1,newRemain = 0;
        vector<int> level;
        while(!record.empty()){
            TreeNode *node = record.front();
            record.pop();
            if(node->left){
                record.push(node->left);
                ++newRemain;
            }
            if(node->right){
                record.push(node->right);
                ++newRemain;
            }
            --remain;
            level.push_back(node->val);
            if(!remain){
                remain = newRemain;
                newRemain = 0;
                result.push_back(level);
                level.clear();
            }
        }
        return result;
    }
};