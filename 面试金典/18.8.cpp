struct Node{
	vector<Node*> nodes;
	Node():nodes(26,nullptr){}
	~Node()
	{
		for (int i=0;i<26;++i)
		{
			delete nodes[i];
		}
	}
};
class Substr {
private:
	Node* root;
public:
	vector<bool> chkSubStr(vector<string> p, int n, string s) {
		construct(s);
		vector<bool> result;
		for(auto x:p){
			result.push_back(check(x));
		}
		return result;
	}

	void construct(const string& s){
		root = new Node();
		for(int i=0;i<s.size();++i){
			string sub = s.substr(i,s.size());
			insert(sub);
		}
	}

	void insert(const string& s){
		Node* p = root;
		for(auto c:s){
			int index = c-'a';
			if(p->nodes[index]==nullptr){
				p->nodes[index] = new Node();
			}
			p = p->nodes[index];
		}
	}

	bool check(const string& s){
		Node* p = root;
		for(auto c:s){
			int index = c-'a';
			if(p->nodes[index]==nullptr){
				return false;
			}
			p = p->nodes[index];
		}
		return true;
	}
};