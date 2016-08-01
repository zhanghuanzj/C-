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
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *newHead = new ListNode(0);
        ListNode *p = head;
        while(p){
            ListNode *pre = newHead;
            while(pre->next && pre->next->val<p->val){
                pre = pre->next;
            }
            ListNode* temp = p->next;
            p->next = pre->next;
            pre->next = p;
            p = temp;
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
};