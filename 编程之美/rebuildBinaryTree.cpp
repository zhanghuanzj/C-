struct Node
{
	Node *left;
	Node *right;
	char c;
};
Node* build(char *pre,int l1,int r1,char *in,int l2,int r2)
{
	if (l1>r1)
	{
		return nullptr;
	}
	else if (l1==r1)
	{
		Node *p = new Node;
		p->left = nullptr;
		p->right = nullptr;
		p->c = *(pre+l1);
		return p;
	}
	else
	{
		Node *p = new Node;
		p->c = *(pre+l1);
		int index;
		for (int i=l2;i<=r2;++i)
		{
			if (*(in+i)==p->c)
			{
				index = i;
				break;
			}
		}
		int dif = index-l2;
		p->left = build(pre,l1+1,l1+dif,in,l2,index-1);
		p->right = build(pre,l1+dif+1,r1,in,index+1,r2);
		return p;
	}
}
void post(Node *p)
{
	if (p==nullptr)
	{
		return;
	}
	post(p->left);
	post(p->right);
	cout<<p->c<<" ";
}
void Rebuild(char *pre,char *in,int len,Node **root)
{
	Node * p = build(pre,0,len-1,in,0,len-1);
	root = &p;
	post(*root);
	cout<<endl;
}