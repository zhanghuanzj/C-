/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode *h1=NULL,*h2=NULL,*p1=NULL,*p2=NULL;
        ListNode *p = pHead;
        while(p!=NULL)
        {
        	if (p->val>=x)
        	{
        		if (h2==NULL)
        		{
        			h2 = p;
        			p2 = p;
        		}
        		else
        		{
        			p2->next = p;
        			p2 = p;
        		}
        	}
        	else
        	{
        		if (h1==NULL)
        		{
        			h1 = p;
        			p1 = p;
        		}
        		else
        		{
        			p1->next = p;
        			p1 = p;
        		}
        	}
            p = p->next;
        }
        if (p2!=NULL)
    	{
    		p2->next = NULL;
    	}
        if (h1!=NULL)
        {
        	p1->next = h2;
        	return h1;
        }
        return h2;
    }
};