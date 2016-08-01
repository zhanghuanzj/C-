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
    ListNode *sortList(ListNode *head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next&&fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *right = slow->next;
        slow->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(right);
        return merge(l1,l2);
    }
    
    ListNode *merge(ListNode* l1,ListNode* l2){
        ListNode *head = new ListNode(1);
        ListNode *p = head;
        while(l1&&l2){
            if(l1->val<l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1){
            p->next = l1;
        }
        if(l2){
            p->next = l2;
        }
        p = head->next;
        delete head;
        return p;
    }
};