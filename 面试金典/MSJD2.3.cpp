/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    bool removeNode(ListNode* pNode) {
        if (pNode==NULL||pNode->next==NULL)
        {
        	return false;
        }
        pNode->val = pNode->next->val;
        ListNode *temp = pNode->next;
        pNode->next = pNode->next->next;
        delete temp;
        return true;
    }
};