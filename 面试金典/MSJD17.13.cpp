/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Converter {
public:
    ListNode* treeToList(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        ListNode* head = nullptr;
        ListNode* cur = new ListNode(root->val);
        ListNode* left = treeToList(root->left);
        ListNode* right = treeToList(root->right);
        if(left==nullptr){
            head = cur;
        }else{
           head = left;
           ListNode* last = left;
           while(last->next){
               last = last->next;
           }
           last->next = cur;
        }
        cur->next = right;
        return head;
    }
};