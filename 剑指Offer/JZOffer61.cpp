
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
    	vector<vector<int>> result;
        if (pRoot==NULL)
        {
        	return result;
        }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        bool flag = true;
        s1.push(pRoot);
        while(!s1.empty()||!s2.empty())
        {
        	vector<int> v;
        	if (flag)
        	{
        		while(!s1.empty())
        		{
        			TreeNode *p = s1.top();
        			s1.pop();
        			v.push_back(p->val);
                    if (p->left!=NULL)
        			{
        				s2.push(p->left);
        			}
        			if (p->right!=NULL)
        			{
        				s2.push(p->right);
        			}
        		}
        	}
        	else
        	{
        		while(!s2.empty())
        		{
        			TreeNode *p = s2.top();
        			s2.pop();
        			v.push_back(p->val);
                    if (p->right!=NULL)
        			{
        				s1.push(p->right);
        			}
        			if (p->left!=NULL)
        			{
        				s1.push(p->left);
        			}
        			
        		}
        	}
        	flag = !flag;
        	result.push_back(v);
        }
        return result;
    }
    
};