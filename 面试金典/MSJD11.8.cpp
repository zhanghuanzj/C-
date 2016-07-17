struct node
{
	node* left;
	node* right;
	int leftNumber;
	int data;
	node(int d):left(nullptr),right(nullptr),leftNumber(0),data(d){}
};
class Rank {
public:
	vector<int> getRankOfNumber(vector<int> A, int n) {
		root = nullptr;
		vector<int> result(n);
		for(int i=0;i<n;++i)
		{
			result[i] = insert(A[i]);
		}
		return result;
	}
private:
	node *root;

	int insert(int x)
	{
		if (root==nullptr)
		{
			root = new node(x);
			return 0;
		}
		else
		{
			int count = 0;
			node* n = root;
			while(n!=nullptr)
			{
				if (n->data>x)
				{
					n->leftNumber++;
					if (n->left==nullptr)
					{
						n->left = new node(x);
						return count;
					}
					n = n->left;
				}
				else if (n->data==x)
				{
					n->leftNumber++;
					return count+n->leftNumber;
				}
				else
				{
					count += n->leftNumber+1;
					if (n->right==nullptr)
					{
						n->right = new node(x);
						return count;
					}
					n = n->right;
				}
			}
		}
		return -1;
	}
};