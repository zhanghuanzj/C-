class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
		int l1 = lenght(pHead1);
		int l2 = lenght(pHead2);
		int dif = max(l1,l2)-min(l1,l2);
		if (l1>=l2)
		{
			while (dif--) pHead1 = pHead1->next;
		}
		else
		{
			while (dif--) pHead2 = pHead2->next;
		}
		while (pHead1!=pHead2)
		{
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return pHead1;
    }
	int lenght(ListNode*p)
	{
		int len = 0;
		while (p)
		{
			p = p->next;
			++len;
		}
		return len;
	}
};