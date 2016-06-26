class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int pre = 0,post = 1,height = 1;
        queue<TreeNode*> q;
        if (root!=NULL)
        {
            q.push(root);
            while(!q.empty())
            {
                if (height==dep)
                {
                    
                    while(!q.empty())
                    {
                        TreeNode *e = q.front();
                        q.pop();
                        ListNode *node = new ListNode(e->val);
                        p->next = node;
                        p = p->next;
                    }
                    return head->next;
                }
                else 
                {
                    TreeNode *treeNode = q.front();
                    q.pop();
                    if (treeNode->left)
                    {
                        q.push(treeNode->left);
                    }
                    if (treeNode->right)
                    {
                        q.push(treeNode->right);
                    }
                    ++pre;
                    if (pre == post)
                    {
                        pre = 0;
                        post = q.size();
                        height++;
                    }
                }
            }
        }
        return NULL;
    }
};