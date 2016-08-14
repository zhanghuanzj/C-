class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode preHead(0);
		preHead.next = head;
		head = &preHead;
		ListNode *pre=nullptr,*post=nullptr;
		for (int i=1;i<=n;++i)
		{
			if (i==m) pre = head;
			if (i==n) post = head->next;
			head = head->next;
		}
		while (pre->next!=post) //中间还有节点需要往post后面插入
		{
			ListNode *p = pre->next; //需要转移的节点
			pre->next = p->next;
			p->next = post->next;
			post->next = p;
		}
		return preHead.next;
    }
};