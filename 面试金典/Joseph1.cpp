class Joseph {
public:
    int getResult(int n, int m) {
        list<int> linklist;
        for(int i=1;i<=n;++i)
        {
        	linklist.push_back(i);
        }
        auto cur = linklist.begin();
        while(linklist.size()>1)
        {
        	for(int i=1;i<m;++i)
        	{
        		++cur;
                if(cur==linklist.end())
                    cur = linklist.begin();
        	}
        	auto temp = cur;
        	++cur;
            if(cur==linklist.end())
                cur = linklist.begin();
        	linklist.erase(temp);
        }
        return linklist.front();
    }
};