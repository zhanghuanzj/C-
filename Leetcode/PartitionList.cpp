class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode lessHead(0);
        ListNode greatHead(0);
        ListNode *less = &lessHead,*great = &greatHead;
        while(head){
            ListNode *temp = head;
            head = head->next;
            if(temp->val < x){
                less->next = temp;
                less = less->next;
            }else{
                great->next = temp;
                great = great->next;
            }
        }
        great->next = nullptr;
        less->next = greatHead.next;
        return lessHead.next;
    }
};