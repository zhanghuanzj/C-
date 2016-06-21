/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        while(fast!=NULL&&fast->next!=NULL)
        {
        	slow = slow->next;
        	fast = fast->next->next;
        }
        if (fast!=NULL)
        {
        	slow = slow->next;
        }
        ListNode *p = pHead;
        return solve(p,slow);
    }
    bool solve(ListNode *&p,ListNode *&slow)
    {
    	if (slow!=NULL&&slow->next!=NULL)
    	{
    		if (!solve(p,slow->next))
    		{
    			return false;
    		}
    		ListNode *temp = p;
    		p = p->next;
    		return temp->val==slow->val;
    	}
    	if (slow!=NULL)
    	{
			ListNode *temp = p;
			p = p->next;
			return temp->val==slow->val;
    	}
    	return false;
    }
};