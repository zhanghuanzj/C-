/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> result;
        solve(head,result);
        return result;
    }
    void solve(struct ListNode* p,vector<int> &result)
    {
    	if (p==NULL)
    	{
    		return;
    	}
    	solve(p->next,result);
    	result.push_back(p->val);
    }
};