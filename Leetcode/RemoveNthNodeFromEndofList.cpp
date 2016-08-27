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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==nullptr || n<1) return head;
        ListNode *p = head;
        for(int i=1;i<n;++i){
            p = p->next;
            if(p==nullptr) return head;
        }
        ListNode node(0);
        node.next = head;
        ListNode *cur = &node;
        while(p->next){
            p = p->next;
            cur = cur->next;
        }
        ListNode *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        return node.next;
    }
};