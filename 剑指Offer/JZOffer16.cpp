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
    ListNode* ReverseList(ListNode* pHead) {
    	ListNode *rHead = NULL;
    	while(pHead)
    	{
    		ListNode *temp = pHead->next;
    		pHead->next = rHead;
    		rHead = pHead;
    		pHead = temp;
    	}
    	return rHead;
    }
};