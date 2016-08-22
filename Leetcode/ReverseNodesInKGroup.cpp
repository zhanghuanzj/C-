class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode node(0);
        node.next = head;
        ListNode *cur = node.next;
        ListNode *pre = &node;
        while(cur){
            int count = 0;
            ListNode *p = nullptr, *q = nullptr;
            while(count<k){
                if(cur==nullptr) break;
                if(count==0) p = cur;
                if(count==k-1) q = cur;
                ++count;
                cur = cur->next;
            }
            if(count==k){
                q->next = nullptr;
                reverse(p);
                p->next = cur;
                pre->next = q;
                pre = p;
            }
        }
        return node.next;
    }
    ListNode *reverse(ListNode *head){
        ListNode *pre = nullptr;
        ListNode *next = nullptr;
        while(head){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};