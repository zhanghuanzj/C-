/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* temp = pListHead;
        int length = 0;
        while(temp)
        {
            ++length;
            temp = temp->next;
        }
        
        if (k<=length)
        {
            ListNode *result = pListHead;
            for (int i = 0; i < length-k; ++i)
            {
                result = result->next;
            }
            return result;
        }
        return NULL;
    }
};