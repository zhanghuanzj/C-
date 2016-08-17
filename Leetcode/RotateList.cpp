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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==nullptr||head->next==nullptr) return head;
        int size = 0;
        for(ListNode *p=head;p;p=p->next){
            ++size;
        }
        k = k%size;
        if(k==0) return head;
        ListNode *slow = head,*fast = head;
        for(int i=0;i<k;++i) fast = fast->next;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* pNode = slow->next;
        fast->next = head;
        slow->next = nullptr;
        return pNode;
    }
};