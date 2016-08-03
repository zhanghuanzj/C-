/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head==NULL) return;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* post = reverse(slow->next);
		slow->next = NULL;
        merge(head,post);
    }
    ListNode* reverse(ListNode* head){
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* des = NULL;
        while(cur){
            ListNode* next = cur->next;
            if(next==NULL)
                des = cur;
            cur->next = pre;
			pre = cur;
            cur = next;
        }
        return des;
    }
    void merge(ListNode* head,ListNode* post){
        ListNode* left = head;
        ListNode* right = post;
        while(right){
            ListNode* rnext = right->next;
            ListNode* lnext = left->next;
            right->next = left->next;
            left->next = right;
            left = lnext;
            right = rnext;
        }
    }
};