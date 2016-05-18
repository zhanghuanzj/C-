
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
    	if (pHead==NULL)
    	{
    		return NULL;
    	}
    	ListNode *pFast = pHead;
    	ListNode *pSlow = pHead;
    	do{
    		pSlow = pSlow->next;
    		if (pFast->next!=NULL)
    		{
    			pFast = pFast->next->next;
    		}
    		else
    		{
    			return NULL;
    		}
    		if (pFast==NULL||pSlow==NULL)
    		{
    			return NULL;
    		}
    	}while(pFast!=pSlow)
    	pSlow = pHead;
    	while(pSlow!=pFast)
    	{
    		pSlow = pSlow->next;
    		pFast = pFast->next;
    	}
    	return pSlow;
    }
};