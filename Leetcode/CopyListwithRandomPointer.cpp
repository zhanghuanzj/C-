struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        cloneList(head);
		randomAdjust(head);
		return seperateList(head);
    }
private:
	void cloneList(RandomListNode *head)
	{
		RandomListNode *node = head;
		while (node)
		{
			RandomListNode *cloneNode = new RandomListNode(node->label);
			cloneNode->next = node->next;
			node->next = cloneNode;
			node = cloneNode->next;
		}
	}

	void randomAdjust(RandomListNode *head)
	{
		RandomListNode *node = head;
		while (node)
		{
			RandomListNode *cloneNode = node->next;
			if (node->random)
			{
				cloneNode->random = node->random->next;
			}	
			node = cloneNode->next;
		}
	}

	RandomListNode* seperateList(RandomListNode *head)
	{
		RandomListNode *node = head;
		RandomListNode *cloneHead = nullptr;
		RandomListNode *cloneNode = nullptr;
		while (node)
		{
			if (cloneNode==nullptr)
			{
				cloneNode = cloneHead = node->next;
			}
			else
			{
				cloneNode->next = node->next;
				cloneNode = cloneNode->next;
			}
			node->next = cloneNode->next;
			node = node->next;
		}
		return cloneHead;
	}
};
