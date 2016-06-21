class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
        vector<vector<int>> stack;
        vector<int> temp;
        for(auto op : ope)
        {
        	if (op[0]==1)   //push
        	{
        		if (temp.size()==size)
        		{
        			stack.push_back(temp);
        			temp.clear();
        		}
        		temp.push_back(op[1]);
        	}
        	else if (op[0]==2) //pop
        	{
        		if (!temp.empty())
        		{
        			temp.pop_back();
        		}
        		else if (!stack.empty())
        		{
        			temp = stack.back();
        			stack.pop_back();
        			temp.pop_back();
        		}
        	}
        }
        if (!temp.empty())
        {
        	stack.push_back(temp);
        }
        return stack;
    }
};