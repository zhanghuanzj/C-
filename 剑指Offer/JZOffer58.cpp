using namespace std;
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode==NULL)
        {
        	return NULL;
        }
        TreeLinkNode *current = pNode;
        if (pNode->right!=NULL)
        {
        	current = pNode->right;
        	while(current->left!=NULL)
        		current = current->left;
        	return current;
        }
        else
        {
        	do{
        		pNode = current;
        		current = pNode->next;
        	}while(current!=NULL&&current->left!=pNode);
        	return current;
        }
    }
};