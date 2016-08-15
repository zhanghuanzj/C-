class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == nullptr) return head;
        ListNode *preNode = head;
        ListNode *curNode = head->next;
        while(curNode){
            if(curNode->val==preNode->val){
                ListNode *temp = curNode;
                curNode = curNode->next;
                delete temp;
            }else{
                preNode->next = curNode;
                preNode = curNode;
                curNode = curNode->next;
            }
        }
        preNode->next = nullptr;
        return head;
    }
};