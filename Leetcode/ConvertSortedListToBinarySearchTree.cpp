/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        int size = 0;
        ListNode *p = head;
        while(p!=NULL){
            p = p->next;
            ++size;
        }
        return generate(head,size);
    }
    TreeNode *generate(ListNode *head,int n){
        if(n==0) return NULL;
        ListNode *p = head;
        for(int i=0;i<n/2;++i){
            p = p->next;
        }
        TreeNode *node = new TreeNode(p->val);
        node->left = generate(head,n/2);
        node->right = generate(p->next,n-n/2-1);
        return node;
    }
};