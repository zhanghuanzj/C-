class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==nullptr) return head;
        ListNode preHead(0);
        preHead.next = head;
        ListNode *befNode = &preHead;
        ListNode *preNode = head;
        ListNode *curNode = head->next;
        bool flag = false;
        while(curNode){
            if(curNode->val==preNode->val){
                ListNode *temp = curNode;
                curNode = curNode->next;
                delete temp;
                flag = true;
            }else{
                if(flag){
                    delete befNode->next;
                    befNode->next = curNode;
                    flag = false;
                }else{
                    preNode->next = curNode;
                    befNode = preNode;              
                }
                preNode = curNode;
                curNode = curNode->next;
            }
        }
        if(flag){
            delete befNode->next;
            befNode->next = nullptr;
        }else{
            preNode->next = nullptr;
        }
        return preHead.next;
    }
};