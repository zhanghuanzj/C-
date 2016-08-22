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
    ListNode *swapPairs(ListNode *head) {
        ListNode node(0);
        node.next = head;
        ListNode *cur = &node;
        while(cur && cur->next &&cur->next->next){
            ListNode *next = cur->next->next->next;
            ListNode *p = cur->next;
            ListNode *q = cur->next->next;
            cur->next = q;
            q->next = p;
            p->next = next;
            cur = p;
        }
        return node.next;
    }
};