class Middle {
public:
	vector<int> getMiddle(vector<int> A, int n) {
		priority_queue<int> leftheap;
		priority_queue<int,vector<int>,greater<int>> rightheap;
		vector<int> result;
		for (auto v : A)
		{
			if (leftheap.size()==rightheap.size())
			{
				if (!rightheap.empty()&&rightheap.top()<v)
				{
					rightheap.push(v);
					v = rightheap.top();
					rightheap.pop();
				}
				leftheap.push(v);
			}
			else
			{
				if (leftheap.top()>v)
				{
					leftheap.push(v);
					v = leftheap.top();
					leftheap.pop();
				}
				rightheap.push(v);
			}
			result.push_back(leftheap.top());
		}
		return result;
	}
};