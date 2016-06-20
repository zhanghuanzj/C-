/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        ListNode *result = NULL;
        ListNode *p = NULL;
        int pre = 0;
        while(a!=NULL&&b!=NULL)
        {
        	int value = a->val+b->val+pre;
        	handle(result,p,value);
        	pre = value/10;
            a = a->next;
            b = b->next;
        }
        while(a!=NULL)
        {
        	int value = a->val+pre;
        	handle(result,p,value);
        	pre = value/10;
            a = a->next;
        }
        while(b!=NULL)
        {
        	int value = b->val+pre;
        	handle(result,p,value);
        	pre = value/10;
            b = b->next;
        }
        if (pre!=0)
        {
        	handle(result,p,pre);
        }
        return result;
    }
    void handle(ListNode *&result,ListNode *&p,int value)
    {
    	ListNode *node = new ListNode(value%10);
    	if (result==NULL)
    	{
    		result = p = node;
    	}
    	else
    	{
    		p->next = node;
    		p = p->next;
    	}
    }
};