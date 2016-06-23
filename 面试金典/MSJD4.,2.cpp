/*
struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};*/

class Path {
public:
	set<UndirectedGraphNode*> visited;
	bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
		if (solve(a,b))
		{
			return true;
		}
		visited.clear();
		return solve(b,a);
	}

	bool solve(UndirectedGraphNode *a,UndirectedGraphNode *b)
	{
		if (a==b)
		{
			return true;
		}
		visited.insert(a);
		for(auto p : a->neighbors)
		{
			if (!visited.count(p)&&solve(p,b))
			{
				return true;
			}
		}
		return false;
	}
};