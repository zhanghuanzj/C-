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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode head(0);
        ListNode *p = &head;
        int carry = 0;
        while(l1&&l2){
            int sum = carry+l1->val+l2->val;
            p->next = new ListNode(sum%10);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
            carry = sum/10;
        }
        while(l1){
            int sum = carry+l1->val;
            p->next = new ListNode(sum%10);
            p = p->next;
            l1 = l1->next;
            carry = sum/10;
        }
        while(l2){
            int sum = carry+l2->val;
            p->next = new ListNode(sum%10);
            p = p->next;
            l2 = l2->next;
            carry = sum/10;
        }
        if(carry) p->next = new ListNode(carry);
        return head.next;
    }
};