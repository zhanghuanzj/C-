/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode *pResult = findNext(pHead);
		ListNode *p = pResult;
		while(p)
		{
			p->next = findNext(p->next);
			p = p->next;
		}
		return pResult;
	}
	ListNode* findNext(ListNode *p)
	{
		if (p==NULL)
		{
			return p;
		}
		int v = p->val;
		while (p!=NULL&&p->next!=NULL&&v==p->next->val)
		{
			while(p!=NULL&&p->val==v)
			{
				ListNode *temp = p;
				p = p->next;
				delete temp;
			}
			if(p)
				v = p->val;
		}
		return p;
	}
};