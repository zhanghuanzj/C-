struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		generateNodes(pHead);
		randomAdjust(pHead);
		return getClonedList(pHead);
	}

	void generateNodes(RandomListNode * pHead)
	{
		RandomListNode *pNode = pHead;
		while (pNode!=nullptr)
		{
			//创建新节点插入
			RandomListNode *p = new RandomListNode(pNode->label);
			p->next = pNode->next;
			p->random = pNode->random;
			pNode->next = p;
			pNode = p->next;
		}
	}

	void randomAdjust(RandomListNode *pHead)
	{
		RandomListNode *pNode = pHead;
		while (pNode!=nullptr)
		{
			if (pNode->random!=nullptr)
			{
				pNode->next->random = pNode->random->next;
			}
			pNode = pNode->next->next;
		}
	}

	RandomListNode* getClonedList(RandomListNode *pHead)
	{
		RandomListNode *pNode = pHead;
		RandomListNode *pCloned = nullptr;
		RandomListNode *pClonedNode = nullptr;
		if (pHead!=nullptr)
		{
			pCloned = pHead->next;
			pClonedNode = pCloned;
			pNode->next = pClonedNode->next;
			pNode = pCloned->next;
		}

		while (pNode!=nullptr)
		{
			pClonedNode->next = pNode->next;
			pClonedNode = pClonedNode->next;
			pNode->next = pClonedNode->next;
			pNode = pNode->next;
		}
		return pCloned;
	}
};