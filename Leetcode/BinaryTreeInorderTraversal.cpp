class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root==nullptr) return result;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty()||!s2.empty()){
            if(!s1.empty()){
                TreeNode* node = s1.top();
                s1.pop();
                if(node->left){
                    s2.push(node);
                    s1.push(node->left);
                }else{
                    result.push_back(node->val);
                    if(node->right){
                        s1.push(node->right);
                    }
                }
            }else if(!s2.empty()){
                TreeNode *node = s2.top();
                s2.pop();
                result.push_back(node->val);
                if(node->right){
                    s1.push(node->right);
                }
            }
        }
        return result;
    }
};